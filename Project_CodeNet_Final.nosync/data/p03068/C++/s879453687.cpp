#include <bits/stdc++.h>
#include <ctype.h>
#include <math.h>
using namespace std;

int N,K;
string S;

int main(){
    cin>>N>>S>>K;

    for(int i=0;i<N;i++){
        if(S[i]!=S[K-1])S[i]='*';
    }
    cout<<S<<endl;
}