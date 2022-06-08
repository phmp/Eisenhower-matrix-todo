#include <iostream>
#include <ctime>
#include <vector>

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

    double daysToDeadLine(){
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

int main(){

    time_t now = time(0);
    time_t yesterday = now - 24*60*60;
    time_t weekAgo = now - 7*24*60*60;

    std::vector < Task > toDoList;
    Task cleanupKitchen( "clean up the kichen", now, true );
    Task cleanupBath( "clean up the bath", yesterday, false );
    Task cleanupCar( "clean up the car", weekAgo, true );
    toDoList.push_back(cleanupKitchen);
    toDoList.push_back(cleanupBath);
    toDoList.push_back(cleanupCar);

    std::cout << "important tasks:" << std::endl;
    for (int i =0 ; i< toDoList.size(); i++){
        Task task = toDoList[i];
        if (task.isImportant()){
            std::cout << "task no. "<< i+1<< ": " << task.getName() << " important? " << task.isImportant() << std::endl;
        }
    }

    std::cout << "urgent tasks:" << std::endl;

    for (int i =0 ; i< toDoList.size(); i++){
        Task task = toDoList[i];
        if (task.isUrgent()){
            std::cout << "task no. "<< i+1<< ": " << task.getName()<< " Days to deadline: " << task.daysToDeadLine() << std::endl;
        }
    }
}

