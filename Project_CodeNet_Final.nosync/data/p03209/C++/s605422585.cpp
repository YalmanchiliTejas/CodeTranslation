#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long int X;
    cin>>N>>X;
    
    vector<long long int> S(N+1),P(N+1);
    S[0]=1;P[0]=1;
        for(int i=1;i<=N;i++){
            S[i]=S[i-1]*2+3;
            P[i]=P[i-1]*2+1;
        }
    long long int cnt=0;
    int M=N;
    while(N>=0){
        if(X>(S[N]-1)/2+(M-N)){
            cnt+=(P[N]-1)/2;
            X-=(S[N]-1)/2;
                cnt++;
            N--;
            continue;
        }
        else{
            N--;
        }
    }
    cout<<cnt<<endl;
}
