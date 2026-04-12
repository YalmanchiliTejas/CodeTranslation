#include<iostream>
#include<string>
using namespace std;

string changeAsterisk(string inputString,int position,int stringLength){
//    cout << inputString << " " << position << " " << stringLength << endl;
    char remainChar=inputString[position-1];
    int scanPosition;
    for(scanPosition = 0;scanPosition < stringLength;scanPosition++){
        if(inputString[scanPosition] != remainChar){
            inputString[scanPosition] = '*';
        }
    }
    return inputString;
}

int main(void){
    string S,outputString;
    int N,K;
    cin >> N;
    cin >> S;
    cin >> K;
    outputString = changeAsterisk(S,K,N);
    cout << outputString << endl;
    return 0;
}