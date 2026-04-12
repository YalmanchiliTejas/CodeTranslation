#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    string S;
    int check;
    do{
        check = 0;
        cin >> S;
        for(int i=0;i<3;i++){
            if(S[i] != 'A' && S[i] != 'B')check = 1;
        }
        
    }while(S.length()!=3 || check == 1);

    if(S=="AAA" || S=="BBB"){
        cout << "No";
    }else{
        cout << "Yes";
    }
    

    return 0;
}