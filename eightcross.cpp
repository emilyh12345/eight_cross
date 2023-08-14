//Emily Haller CSCI 211
#include<iostream>
using namespace std;

void print(int q[]){
	static int solutions=0; 
	solutions++; //increment solutions to keep track of the number solution we are up to 
	cout << "Solution " << solutions << ":" << endl;
        cout << " " << q[0] << q[1] << " " << endl; //print out each element in array q to print the eight cross
        cout << q[2] << q[3] << q[4] << q[5] << endl;
        cout<< " " << q[6] << q[7] << " " << endl; 
	cout << endl;
}

bool okay(int q[], int c){  //function to test if the placement of each number works
	static int helperArray[8][5]={ //helper function to tell which boxes are adjacent for each box
		{-1}, //box 0, -1 since not checking any box because no other numbers were put down
        	{0, -1}, //box 1
        	{0, -1}, //box 2
        	{0, 1, 2, -1}, //box 3
        	{0, 1, 3, -1}, //box 4
        	{1, 4, -1}, //box 5
        	{2, 3, 4, -1}, //box 6
        	{3, 4, 5, 6, -1} //box 7
        };
	for (int i=0; i<c; i++){ //loop through the array to see if a number has already been placed
        	if (q[c]==q[i]){ 
			return false; //indicates this is an invalid configuration 
        	}
    	}
	for (int i=0; helperArray[c][i]!=-1; i++){ //loops to check adjacent boxes for consecutive integers(until no more boxes to check)
        	if (q[(helperArray[c][i])]==q[c]+1 || q[(helperArray[c][i])]==q[c]-1){
                	return false; //failed since there are consecutive integers in adjacent boxes 
        	}
        }
	return true; //indicates that both tests were passed
}

int main(){
	int q[8]={1, 1, 1, 1, 1, 1 ,1, 1}, c=0; //initialize array to contain ones to start
   	while (c!=-1){ // while we didnt find all solutions
        	if (c>7){ //if exceeded our last index then print it since we have a solution
            		print(q); 
            		q[c]=1; //reset the number in the box to 1 in order to start to backtrack
            		c--; //go back a box in order to backtrack
            		if (c==-1){ //check if column is -1(off the board) and then youre done(found all solutions) 
                		return 0; 
            		} else {
                		q[c]++; //increment the number in the box to continue checking for numbers that work since we havent found all solutions yet
            		}
        	}
		if (q[c] == 9){ //ran out of numbers to try
           		q[c]=1; //reset the number in the box to 1 to start to backtrack
            		c--; //go back a box to backtrack
            		if (c==-1){ //check if column is -1(off the board) and then youre done(found all solutions) 
                		return 0; 
            		} else {
                		q[c]++; //increment the number in the box to continue checking for numbers that work since we havent found all solutions yet
        		}
        	}
		else if (okay(q, c)){
                	c++; //go to next box since its a valid configuration
        	} else {
           		q[c]++; //otherwise increment number in the box since it isnt a valid configuration
        	}
    	}
    	cout << "All done"; //when c= -1(off board) we have found all solutions
    	return 0;
}
