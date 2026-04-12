#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    string V="AB";
    cin>>S;
    if(S.length()==3){
        if((S[0]==V[0]||S[1]==V[0]||S[2]==V[0])&&(S[0]==V[1]||S[1]==V[1]||S[2]==V[1])){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
    }
   return 0;
}