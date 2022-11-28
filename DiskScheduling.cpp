//disk scheduling algorithms

#include <iostream>
using namespace std;

int arr[][2] {{82, 0}, {170, 0}, {43, 0}, {140, 0}, {24,0}, {16,0}, {190,0}};
int n = sizeof(arr)/sizeof(arr[0]);
//column 1 for the reading points of processes
//column 2 for the flags
int FCFS(int arr[][2], int n, int head) {
    int time_taken{};
    time_taken = abs(head-arr[0][0]);
    arr[0][1] = 1;
    for(int i =1; i<n; i++) {
        time_taken+= abs(arr[i-1][0]-arr[i][0]);
        arr[i][1] = 1;
    }

    return time_taken;
}

int SJF(int arr[][2], int n, int head) {
    int time_taken{}, index{}, counter{};
    //find min(head-arr[i][0]);

    while(true) {
    int min = INT32_MAX;
    for(int i =0; i<n;i++) {
        if(arr[i][1]==0&&min>abs(head-arr[i][0])) {
            min = abs(head-arr[i][0]);
            index = i;
        }
    }
    time_taken+= abs(head- arr[index][0]);
    arr[index][1] = 1;
    counter++;
    head = arr[index][0];
    if(counter == n)
        break;
    }
    return time_taken;
}

int SCAN(int arr[][2], int n, int head) {
    int index{}, time_taken{};

        for(int i =0; i<n-1; i++) {
            for(int j = 0; j<n-i-1; j++) {
                if(arr[j][0]>arr[j+1][0])
                    swap(arr[j][0], arr[j+1][0]);
            }
        }
        //find the index closest to the head
        int min {INT32_MAX};
        for(int i =0; i<n; i++) {
            if(arr[i][0]-head>0&&min>arr[i][0]- head) {
                min = arr[i][0]- head;
                index = i;
            }
        }
        for(int i = index; i <n; i++) {
            if(arr[i][1] == 0) {
                time_taken += arr[i][0] - head;
                head = arr[i][0];
                arr[i][1] =1;
            }
        }
        time_taken+= head - arr[index-1][0];
        head = arr[index-1][0];
        for(int i = index-2; i>=0; i--) {
            time_taken+= head - arr[i][0];
            head = arr[i][0];
        }
    return time_taken;
}

int CSCAN(int arr[][2], int n, int head) {
    int index{}, time_taken{};
    for(int i =0; i<n-1; i++) {
        for(int j =0; j<n-i-1;j++) {
            if(arr[j][0]>arr[j+1][0])
                swap(arr[j][0], arr[j+1][0]);
        }
    }

    //find the nearest index to head;
    int min{INT32_MAX};
    for(int i = 0; i<n; i++) {
        if(arr[i][0] - head>0&&min>arr[i][0]-head) {
            min = arr[i][0]-head;
            index = i;
        }
    }
    for(int i =index; i<n; i++) {
        time_taken+= arr[i][0] - head;
        head = arr[i][0];
    }
    time_taken+= (end-head)+(end-start);
    head = start;
    for(int i =0;i<index; i++) {
        time_taken+= arr[i][0] - head;
        head = arr[i][0];
    }
    return time_taken;
}

int LOOK(int arr[][2], int n, int head) {
    //similar to SCAN doesnt go till the end
}

int CLOOK(int arr[][2], int n, int head) {
    //similar to CSCAN doesnt go till the end
}

int main() {
    cout<<SJF(arr,n,50);
    return 0;
}
}
