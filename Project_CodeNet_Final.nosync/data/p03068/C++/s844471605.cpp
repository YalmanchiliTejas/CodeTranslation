#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;
 
int main(){
    
    int N,K;
    char S[10],Ans[10],Ck;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> S[i];
    }

    cin >> K;
    Ck = S[K-1];

    for(int i=0;i<N;i++){
        if(S[i]!=Ck){
            Ans[i]='*';
        }else{
            Ans[i]=S[i];
        }
    }

    for(int i=0;i<N;i++){
        cout<<Ans[i];
    }

    return 0;

}