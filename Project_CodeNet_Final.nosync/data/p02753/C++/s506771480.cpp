#include <bits/stdc++.h>
using namespace std;

int main(){
    char S[3];
    cin>>S;
    

    if (S[0]==S[1]&&S[1]==S[2]&&S[2]==S[0])
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    
    return 0;
}