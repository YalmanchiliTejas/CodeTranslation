#include<iostream>
#include<string>
#include <algorithm>

using namespace std;


int main(){
    int N;
    cin >> N;
    int* array;
    array = new int[N];
    int i;
    for(i = 0; i<N; i++){
        cin >> array[i];
    }
    int max;
    max = array[0];
    int counter = 1;
    for(i = 1; i<N; i++){
        if(array[i]>=max){
            counter++;
            max = array[i];
        }
    }
    cout << counter << endl;
}