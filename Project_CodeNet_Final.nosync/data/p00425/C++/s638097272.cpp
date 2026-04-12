#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    while(true) {
        cin >> n;
        if(n==0) break;
        vector<int> face(6);
        int score=1;
        face[0]=1;
        face[1]=2;
        face[2]=3;
        face[3]=5;
        face[4]=4;
        face[5]=6;
        for(int i=0; i<n; ++i){
            string dir;
            cin >> dir;
            if(dir=="North") {
                int temp;
                temp=face[0];
                face[0]=face[1];
                face[1]=face[5];
                face[5]=face[3];
                face[3]=temp;
            } else if(dir=="East") {
                int temp;
                temp=face[0];
                face[0]=face[4];
                face[4]=face[5];
                face[5]=face[2];
                face[2]=temp;
            } else if(dir=="West") {
                int temp;
                temp=face[0];
                face[0]=face[2];
                face[2]=face[5];
                face[5]=face[4];
                face[4]=temp;
            } else if(dir=="South") {
                int temp;
                temp=face[0];
                face[0]=face[3];
                face[3]=face[5];
                face[5]=face[1];
                face[1]=temp;
            } else if(dir=="Right") {
                int temp;
                temp=face[1];
                face[1]=face[2];
                face[2]=face[3];
                face[3]=face[4];
                face[4]=temp;
            } else if(dir=="Left") {
                int temp;
                temp=face[1];
                face[1]=face[4];
                face[4]=face[3];
                face[3]=face[2];
                face[2]=temp;
            }
            score+=face[0];
        }
        cout << score << endl;
    }
    return 0;
}

