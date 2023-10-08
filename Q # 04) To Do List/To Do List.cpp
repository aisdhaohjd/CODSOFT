#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the list
void addTask(std::vector<Task>& taskList, const std::string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    taskList.push_back(task);
    std::cout << "Task added: " << description << std::endl;
}

// Function to view tasks in the list
void viewTasks(const std::vector<Task>& taskList) {
    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        const Task& task = taskList[i];
        std::cout << i + 1 << ". " << (task.completed ? "[X] " : "[ ] ") << task.description << std::endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(std::vector<Task>& taskList, size_t index) {
    if (index >= 0 && index < taskList.size()) {
        taskList[index].completed = true;
        std::cout << "Task marked as completed: " << taskList[index].description << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& taskList, size_t index) {
    if (index >= 0 && index < taskList.size()) {
        std::cout << "Task removed: " << taskList[index].description << std::endl;
        taskList.erase(taskList.begin() + index);
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> taskList;

    std::cout << "Simple To-Do List Manager" << std::endl;
    while (true) {
        std::cout << "\nOptions:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(taskList, description);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                std::cout << "Enter the index of the task to mark as completed: ";
                size_t index;
                std::cin >> index;
                markTaskAsCompleted(taskList, index - 1); // Adjust for 0-based index
                break;
            }
            case 4: {
                std::cout << "Enter the index of the task to remove: ";
                size_t index;
                std::cin >> index;
                removeTask(taskList, index - 1); // Adjust for 0-based index
                break;
            }
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
