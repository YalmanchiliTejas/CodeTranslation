#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char x[5];
    char s[100][1000];
    char c;
    char pu[10]={"push"};
    char po[10]={"pop"};
    char mo[10]={"move"};
    int rear[100]={0};
    int n,i,j;
    
    cin >> n;
    while(1){
        cin >> x;
        if(strcmp(x,pu)==0){
            cin >> i >> c;
            s[i][rear[i]]= c;
            rear[i]++;
        }
        else if(strcmp(x,po)==0){
            cin >> i;
            cout << s[i][rear[i]-1] << endl;
            rear[i]--;
        }
        else if(strcmp(x,mo)==0){
            cin >> i >> j;
            s[j][rear[j]]=s[i][rear[i]-1];
            rear[j]++;
            rear[i]--;
        }
        else break;
    }
    return 0;
}