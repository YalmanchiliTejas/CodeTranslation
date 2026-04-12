#include <iostream>
using namespace std;

int n;
string S[50];

int count[50][26];
const int a = int('a');

void readInput(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
}

void initCountArray(){
    for(int i=0; i<50; i++){
        for(int j=0; j<26; j++){
            ::count[i][j]=0;
        }
    }
}

void countChar(){
    for(int i=0; i<n; i++){
        int size = S[i].size();
        for(int j=0; j<size; j++){
            int c = int(S[i][j])-a;
            ::count[i][c]++;
        }
    }
}

void printOutput(){
    int min;
    for(int i=0; i<26; i++){
        min = 10000;
        for(int j=0; j<n; j++){
            if(min > ::count[j][i]){
                min = ::count[j][i];
            }
        }
        for(int j=0; j<min; j++){
            cout << char(i+a);
        }
    }
    cout << endl;
}

int main(void){
    readInput();
    initCountArray();
    countChar();
    printOutput();
    return 0;
}
