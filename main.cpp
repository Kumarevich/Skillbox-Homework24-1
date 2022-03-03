#include <iostream>
#include <ctime>
#include <fstream>

void status()
{
    std::ifstream db("..\\DB.txt");
    std::string nameTemp;
    double timeTemp;
    while (!db.eof()) {
        db >> nameTemp >> timeTemp;
        std::cout << nameTemp << " " << timeTemp << std::endl;
    }
}

void end(std::time_t* startTime, std::string* currentTask)
{
    std::ofstream db("..\\DB.txt", std::ios::app);
    std::time_t endTime = std::time(nullptr);
    double taskTime = std::difftime(endTime, *startTime);
    db << std::endl << *currentTask << " " << taskTime;
    db.close();
    *currentTask = "";
}

void begin(std::time_t* startTime, std::string* currentTask)
{
    if (*currentTask != "") end(startTime, currentTask);
    std::cout << "Input a new task name: ";
    std::cin >> *currentTask;
    *startTime = std::time(nullptr);
}

int main() {
    std::string input, currentTask;
    std::time_t startTime;
    std::time_t endTime;
    while (input != "exit") {
        std::cout << "Input the command: ";
        std::cin >> input;
        if (input == "begin") begin(&startTime, &currentTask);
        else if (input == "end") end(&startTime, &currentTask);
        else if (input == "status") status();
        else if (input != "exit") std::cout << "Wrong input. Try again." << std::endl;
    }
        return 0;
}