#include<iostream>

using namespace std;

char put_str(const char s[],int k){
    char same;
    for(int i=0;s[i]!=0;i++){
        if(i+1 == k){
            same =s[i];
        }
    }
    return same;
}

int main(){
    int n,k;
    char s[10];
    char same;
    cin >> n;
    cin >> s;
    cin >> k;
    same = put_str(s,k);
    for(int i=0;s[i]!=0;i++){
        if(s[i]!=same){
            cout << "*";
        }
        else{
            cout << s[i];
        }
    }
}