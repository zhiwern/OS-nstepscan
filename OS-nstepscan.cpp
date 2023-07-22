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

//scan up routine
void nstepScanUp(int *nextArmLocation , int *travelDistant, int *currentArmLocation, int initialArmLocation, int *requestLocations, int arraySize) {
    int count = 0;
    int totalTravel = 0;
    //sets the current arm pointer location
    currentArmLocation[0] = initialArmLocation;
    for (int i = 0; i < arraySize; i++) {
        if (currentArmLocation[count] < requestLocations[i]) { 
            //transverse to new location if its greater than the current location
            nextArmLocation[count] = requestLocations[i];
            currentArmLocation[count + 1] = nextArmLocation[count];
            travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
            count++;
        }
    }
    //resets the current location to the max which is 199 and back to zero to restart the pointer
    if (currentArmLocation[count] != 199) {
        nextArmLocation[count] = 199;
        currentArmLocation[count + 1] = nextArmLocation[count];
        travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
        arraySize++;
        count++;
    }
    nextArmLocation[count] = 0;
    currentArmLocation[count + 1] = nextArmLocation[count];
    travelDistant[count] = currentArmLocation[count]-nextArmLocation[count];
    arraySize++;
    count++;
    //transverse the remaining locations from the bottom.
    for (int i = 0; i < arraySize; i++) {
        if (initialArmLocation > requestLocations[i]) {
            nextArmLocation[count] = requestLocations[i];
            currentArmLocation[count + 1] = nextArmLocation[count];
            travelDistant[count] = nextArmLocation[count]-currentArmLocation[count];
            count++;
        }
    }
    //Print to standard output
    cout << "Initial arm position: " << initialArmLocation << "\n\n";
    cout << "Start" << "\t" << "Finish" << "\t" << "Track Travelled" << "\n";
    for (int i = 0; i < arraySize; i++) {
        cout << currentArmLocation[i] << "\t" << nextArmLocation[i] << "\t" << travelDistant[i] << "\n";
    }

    //Total distant
    for (int i = 0; i < arraySize; i++)
    {
            totalTravel = totalTravel + travelDistant[i];
    }
    cout << "\n" << "Total travel:\t" << totalTravel << "\n";
}

//scan down routine
void nstepScanDown(int* nextArmLocation, int* travelDistant, int* currentArmLocation, int initialArmLocation, int* requestLocations, int arraySize) {
    int count = 0;
    int totalTravel = 0;
    currentArmLocation[0] = initialArmLocation;
    for (int i = arraySize; i >= 0; i--) {
        if (currentArmLocation[count] > requestLocations[i]) {
            nextArmLocation[count] = requestLocations[i];
            currentArmLocation[count + 1] = nextArmLocation[count];
            travelDistant[count] =  currentArmLocation[count]- nextArmLocation[count];
            count++;
        }
    }
    if (currentArmLocation[count] != 0) {
        nextArmLocation[count] = 0;
        currentArmLocation[count + 1] = nextArmLocation[count];
        travelDistant[count] = currentArmLocation[count]-nextArmLocation[count];
        count++;

    }
    nextArmLocation[count] = 199;
    currentArmLocation[count + 1] = nextArmLocation[count];
    travelDistant[count] = nextArmLocation[count] - currentArmLocation[count];
    count++;
    
    for (int i = arraySize-1; i >= 0; i--) {
        if (initialArmLocation < requestLocations[i]) {
            nextArmLocation[count] = requestLocations[i];
            currentArmLocation[count + 1] = nextArmLocation[count];
            travelDistant[count] =   currentArmLocation[count]-nextArmLocation[count];
            count++;
        }
    }
    //Print to standard output
    cout << "Initial arm position: " << initialArmLocation << "\n\n";
    cout << "Start" << "\t" << "Finish" << "\t" << "Track Travelled" << "\n";
    for (int i = 0; i < arraySize+2; i++) {
        cout << currentArmLocation[i] << "\t" << nextArmLocation[i] << "\t" << travelDistant[i] << "\n";
    }

    //Total distant
    for (int i = 0; i < arraySize+2; i++)
    {
            totalTravel = totalTravel + travelDistant[i];
    }
    cout << "\n" << "Total travel:\t" << totalTravel << "\n";
}

int main()
{
    int requestLocations[9];
    int initialArmLocation = 50;

    int totalTravel = 0;
    int nextArmLocation[100];
    int travelDistant[100];
    int currentArmLocation[100];
    int condition;
    
    int arraySize = sizeof(requestLocations) / sizeof(requestLocations[0]);
    
    cout << "Enter arm initial position: ";
    cin >> initialArmLocation;
    cout << "\n";
    for (size_t i = 0; i < 9; i++)
    {
        cout << "Enter the number of track requests number "<< i<<" : ";
        cin >> requestLocations[i];
    }
    
    //To select the UP or DOWN mode
    cout << "\n1)Up or 2)Down\n";
    cin >> condition;
    bubbleSort(requestLocations, arraySize);
    switch (condition)
    {
    case 1:
        cout << "Scan up sequence\n";
        nstepScanUp(nextArmLocation, travelDistant, currentArmLocation, initialArmLocation, requestLocations, arraySize);
        break;
    case 2:
        cout << "Scan down sequence\n";
        nstepScanDown(nextArmLocation, travelDistant, currentArmLocation, initialArmLocation, requestLocations, arraySize);
        break;
    default:
        break;
    }

    
    while (true)
    {
        
    }
}

