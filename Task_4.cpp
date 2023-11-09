#include <iostream>
#include <string>
#define MaxTasks 100

using namespace std;

struct Task {
    string description;
    bool completed;

    Task() {}
    Task(string description){
        this->description = description;
        this->completed = false;
    }
};

class ToDoList {
private:
    Task tasks[MaxTasks];
    int numTasks;

public:
    ToDoList() {
        this->numTasks = 0;
    }

    // Function to add a task to the list
    void addTask(string description) {
        if (numTasks < MaxTasks) {
            tasks[numTasks] = Task(description);
            numTasks++;
            cout << "Task added: " << description << endl;
        } else {
            cout << "Task list is full. Cannot add more tasks." << endl;
        }
    }

    // Function to view the list of tasks
    void viewTasks() {
        if (numTasks == 0) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (int i = 0; i < numTasks; i++) {
                cout << i + 1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
            cout << endl;
        }
    }

    // Function to mark a task as completed
    void markTaskAsCompleted(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= numTasks) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed: " << tasks[taskNumber - 1].description << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    // Function to remove a task from the list
    void removeTask(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= numTasks) {
            cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
            for (int i = taskNumber - 1; i < numTasks - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main(int argc, char** argv) {
    ToDoList toDoList;
    int choice;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string taskDescription;
            cout << "Enter the task description: ";
            cin >> taskDescription;
            toDoList.addTask(taskDescription);
        } else if (choice == 2) {
            toDoList.viewTasks();
        } else if (choice == 3) {
            int taskNumber;
            cout << "Enter the task number to mark as completed: ";
            cin >> taskNumber;
            toDoList.markTaskAsCompleted(taskNumber);
        } else if (choice == 4) {
            int taskNumber;
            cout << "Enter the task number to remove: ";
            cin >> taskNumber;
            toDoList.removeTask(taskNumber);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
