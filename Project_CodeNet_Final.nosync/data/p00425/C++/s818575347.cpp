#include <iostream>
#include <string>
#include <map>

using namespace std;

const string North = "North";
const string South = "South";
const string East = "East";
const string West = "West";
const string Right = "Right";
const string Left = "Left";

int main(void){
    // Your code here!
    while(true){
        int N;
        cin >> N;
        if(N == 0){
            break;
        }
        int northNum = 5;
        int southNum = 2;
        int eastNum = 3;
        int westNum = 4;
        int top = 1;
        int ans = 0;
        for(int i=0;i<N;i++){
            string ope;
            cin >> ope;
            if(ope == North){
                int temp = top;
                top = southNum;
                southNum = 7 - temp;
                northNum = temp;
            }else if(ope == South){
                int temp = top;
                top = northNum;
                northNum = 7 - temp;
                southNum = temp;
            }else if(ope == East){
                int temp = top;
                top = westNum;
                westNum = 7 - temp;
                eastNum = temp;
            }else if(ope == West){
                int temp = top;
                top = eastNum;
                eastNum = 7 - temp;
                westNum = temp;
            }else if(ope == Right){
                int temp = northNum;
                northNum = westNum;
                westNum = southNum;
                southNum = eastNum;
                eastNum = temp;
            }else if(ope == Left){
                int temp = northNum;
                northNum = eastNum;
                eastNum = southNum;
                southNum = westNum;
                westNum = temp;
            }
            ans += top;
        }
        
        cout<< ans + 1 <<endl;
    }
    return 0;
}

