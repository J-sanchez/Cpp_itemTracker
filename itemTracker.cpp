/*
Name: Jonathan C. Sanchez
Date: 03/03/2024
Purpose: The purpose of this project is to fulfill the request made a local grocery store. The store wants a program that allows them to easily track and report on items purchased throughout the day. (7-3 project 3)
*/

// Import Libraries
#include <iostream> 
#include <map> 
#include <fstream>
#include <string>

//Standard namespace
using namespace std; 

//define itemTracker
class itemTracker {
    private:
    // track the frequency of items
        map<string, int> frequency;

    public:
    //Constructor to read in .txt file and update
    itemTracker(){
        ifstream infile("resources/CS210_Project_Three_Input_File.txt");
        string item;
        //loop through items
        while(infile >> item){
            frequency[item]++;
        }
    }
    //update frequency
    int getFrequency(string item){
        return frequency[item];
    }
    //Print list of items & frequency as a count 
    void displayList(){
        for(auto const&[item, count]:frequency){
            cout << item << " " << count << endl;
        }
    }
//Print list of items & frequency as a histogram
    void displayHistogram(){
        for(auto const&[item, count]:frequency){
            cout << item << " ";
            for (int i = 0; i < count; i++){
                cout << "*";
            }
            cout << endl;
        }
    }
    //updates/writes frequency to file
    void updateDatFile() {
        ofstream outfile("frequency.dat");
        for(auto const&[item, count]: frequency){
            outfile << item << " " << count << endl;
        }
    }
};
// main class
int main(){
    //itemTracker object
    itemTracker tracker;
    //Loop till user inputs a valid choice
    while (true){
        cout << "Menu Options:" << endl;
        cout << "1. Input an item to search" << endl;
        cout << "2. Print a list of items and frequency" << endl;
        cout << "3. Print a list of items and frequency as histogram" << endl;
        cout << "4. Exit Program" << endl;

        int choice;
        cin >> choice;
// Create the cases for the choices in the menu
        switch (choice)
            {
            case 1: {
                string item;
                cout << "Enter item name to look up frequency: ";
                cin >> item;
                cout << " Frequency of " << item << ": " << tracker.getFrequency(item) << endl;
            }
                break;

            case 2:{
                tracker.displayList();
                tracker.updateDatFile();
            }
                break;
        
            case 3: {
                tracker.displayHistogram();
                tracker.updateDatFile();
            }
                break;

            case 4: {
                tracker.updateDatFile();
            }
                return 0;
            
            default: {
                cout << "Invalid choice, please retry." << endl;
            }
                break;
            
        }
        return 0;
    }
}