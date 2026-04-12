#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
using namespace std;

int main(){
    int N;cin>>N;
    long long X;cin>>X;
    
    long long count_P[60];    //Pの個数
    count_P[0]=1;
    for(int i=1;i<=N;i++)
        count_P[i]=1+2*count_P[i-1];
    
    long long leng[60];      //バーガーの長さ
    leng[0]=1;
    for(int i=1;i<=N;i++)
        leng[i]=3+2*leng[i-1];
    
    long long ans=0;
        int i=N-1;
        long long Y=X;
        while(i>=0){
            if(Y>=2+leng[i]){
                ans+=1+count_P[i];
                Y-=2+leng[i];
            }
            else Y--;
            i--;
        }
        if(Y>0)
            ans++;
    
    cout<<ans<<endl;
    return 0;
    
}