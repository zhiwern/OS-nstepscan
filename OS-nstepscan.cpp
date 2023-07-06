// OS-nstepscan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void nstepScan(int *nextArmLocation , int *travelDistant, int *currentArmLocation, int initialArmLocation, int *requestLocations, int arraySize) {
    int count = 0;
    currentArmLocation[0] = initialArmLocation;
    for (int i = 0; i < arraySize; i++) {
        if (currentArmLocation[count] < requestLocations[i]) {
            nextArmLocation[count] = requestLocations[i];
            currentArmLocation[count + 1] = nextArmLocation[count];
            travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
            count++;
        }
    }
    if (currentArmLocation[count] != 199) {
        nextArmLocation[count] = 199;
        currentArmLocation[count + 1] = nextArmLocation[count];
        travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
        arraySize++;
        count++;

    }
    nextArmLocation[count] = 0;
    currentArmLocation[count + 1] = nextArmLocation[count];
    travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
    arraySize++;
    count++;

    for (int i = 0; i < arraySize; i++) {
        if (initialArmLocation > requestLocations[i]) {
            nextArmLocation[count] = requestLocations[i];
            currentArmLocation[count + 1] = nextArmLocation[count];
            travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
            count++;
        }
    }
}

int main()
{
    int requestLocations[] ={10,24,37,52,73,85,112,149,175};
    int initialArmLocation = 50;

    int totalTravel = 0;
    int nextArmLocation[100];
    int travelDistant[100];
    int currentArmLocation[100];
    
    int arraySize = sizeof(requestLocations) / sizeof(requestLocations[0]);
    bubbleSort(requestLocations, arraySize);
    nstepScan(nextArmLocation, travelDistant, currentArmLocation, initialArmLocation, requestLocations, arraySize);

    //Print to standard output
    cout << "Initial arm position: " << initialArmLocation << "\n\n";
    cout << "Start" << "\t" << "Finish" << "\t" << "Track Travelled" << "\n";
    for (int i = 0; i < arraySize+2; i++) {
        cout <<  currentArmLocation[i] << "\t" << nextArmLocation[i] << "\t" << travelDistant[i] << "\n";
    }

    //Total distant
    for (int i = 0; i < arraySize+2; i++)
    {
        if (travelDistant[i] == -199) {
            totalTravel = totalTravel + 199;
        }
        else {
               totalTravel = totalTravel + travelDistant[i];
        }
        
    }
    cout <<"\n" << "Total travel:\t" << totalTravel << "\n";
    while (true)
    {
        
    }
}

