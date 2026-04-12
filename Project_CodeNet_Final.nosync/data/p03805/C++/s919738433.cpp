#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M; cin >> N >> M;
    vector<int> a(M),b(M);
    for(int i=0; i<M; i++){
        cin >> a.at(i) >> b.at(i);
    }
    vector<int> order(N);
    for(int i=0; i<N; i++){
        order.at(i)=i+1;
    }
    int ans=0;

    do{
        if(order.at(0)!=1) break;
        int flag=0;
        for(int i=0; i<N-1; i++){
            int cnt=0;
            for(int j=0; j<M; j++){
                
                if((order.at(i)==a.at(j)&&order.at(i+1)==b.at(j)) || (order.at(i)==b.at(j)&&order.at(i+1)==a.at(j))) cnt=1;
           }
           if(cnt==0){
               flag=0;
               break;
           }
           else flag=1;
            
       }
       if(flag==1) ans++;
    }while(next_permutation(order.begin(),order.end()));
    cout << ans << endl;
}
