#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;

int main(void){
    long long N,K;
    long long answer=0;
    cin>>N>>K;
    if(K==0){
        cout<<N*N<<endl;
    }else{
        for(int b=K+1;b<=N;b++){
            int sequence=(1+N)/b;
            answer+=sequence*(b-K);
            int remain=1+N-sequence*b-K;
            if(remain>=1){
                answer+=remain;
            }
        }
        cout<<answer<<endl;
    }
    
    

	
    return 0;
}
