#include <iostream>
#include <ctime>
#include <vector>

#include <bits/stdc++.h>


class Task{
    private:
    std::string name;
    time_t deadline;
    bool important;
    bool done;

    public:
    Task(std::string name, time_t deadline, bool important){
        this -> name = name;
        this -> deadline = deadline;
        this -> important = important;
        this -> done = false;
    }

    std::string getName(){
        return name;
    }

    bool isUrgent(){
        time_t now = time(0);
        double diff = difftime(now, deadline);
        return diff <= 72 * 60 * 60;
    }

    bool isImportant(){
        return important;
    }

    char * formattedDeadline(){
        return ctime(&deadline);
    }

    int daysToDeadLine(){
        time_t now = time(0);
        double diff = difftime(now, deadline);
        return diff / 24 / 60 / 60;
    }

    void complete(){
        done = true;
    }

    bool isDone(){
        return done;
    }
};

bool byPriorytet(Task task1, Task task2){
    return task1.isImportant() > task2.isImportant();
}
bool byDeadline(Task task1, Task task2){
    return task1.daysToDeadLine() < task2.daysToDeadLine();
}

void printImportantTasks(std::vector < Task > toDoList){
        std::cout << "important tasks:" << std::endl;
    for (int i =0 ; i< toDoList.size(); i++){
        Task task = toDoList[i];
        if (task.isImportant()){
            std::cout << "task no. "<< i+1<< ": " << task.getName() << " important? " << task.isImportant() << std::endl;
        }
    }
}

void printUrgentTasks(std::vector < Task > toDoList){
    std::cout << "urgent tasks:" << std::endl;
    for (int i =0 ; i< toDoList.size(); i++){
        Task task = toDoList[i];
        if (task.isUrgent()){
            std::cout << "task no. "<< i+1<< ": " << task.getName()<< " Days to deadline: " << task.daysToDeadLine() << std::endl;
        }
    }
}

void printSortedByImportancy(std::vector < Task > toDoList){
    std::cout << "sort by importancy" << std::endl;
    sort(toDoList.begin(), toDoList.end(), byPriorytet);
    for (int i =0 ; i< toDoList.size(); i++){
        Task task = toDoList[i];
        std::cout << "task no. "<< i+1<< ": " << task.getName() << " important? " << task.isImportant() << std::endl;
    }
}

void printSortedByUrgency(std::vector < Task > toDoList){
    std::cout << "sort by deadline" << std::endl;
    sort(toDoList.begin(), toDoList.end(), byDeadline);
    for (int i =0 ; i< toDoList.size(); i++){
        Task task = toDoList[i];
        std::cout << "task no. "<< i+1<< ": " << task.getName()<< " Days to deadline: " << task.daysToDeadLine() << std::endl;
    }
    
}

int menu(){
    std::cout << "What to do with TO DO list?" << std::endl;
    std::cout << "1. print important tasks" << std::endl;
    std::cout << "2. print ugent tasks" << std::endl;
    std::cout << "3. print tasks sorted by importancy" << std::endl;
    std::cout << "4. print tasks sorted by urgency" << std::endl;
    std::cout << "0. exit" << std::endl;
    int choose=0;
    std::cin >> choose;
    return choose;
}

int main(){

    time_t now = time(0);
    time_t yesterday = now - 24*60*60;
    time_t weekAgo = now - 7*24*60*60;
    Task cleanupKitchen( "clean up the kichen", now, true );
    Task cleanupBath( "clean up the bath", yesterday, false );
    Task cleanupCar( "clean up the car", weekAgo, true );
    Task groceries( "groceries", weekAgo, false );

    std::vector < Task > toDoList {cleanupKitchen, cleanupBath, cleanupCar, groceries};

    while (int choose = menu()){
        if (choose == 1){
            printImportantTasks(toDoList);
        } else if (choose == 2){
            printUrgentTasks(toDoList);
        } else if (choose == 3){
            printSortedByImportancy(toDoList);
        } else if (choose == 4){
            printSortedByUrgency(toDoList);
        } else {
            std::cout << "wrong input" << std::endl;
        }
    }

}
