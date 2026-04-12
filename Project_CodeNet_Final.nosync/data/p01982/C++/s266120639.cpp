#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int N,L,R;
        cin>>N>>L>>R;
        if(N == 0 && L == 0 && R == 0) break;
        vector<int> A(N);
        for(int i=0; i<N; i++) cin>>A[i];

        int cnt = 0;

        for(int x=L; x<=R; x++){
        
            bool flag = false;
            bool exist = false;

            for(int i=0; i<N; i++){
                if(x % A[i] == 0){
                    if((i+1) % 2 != 0) flag = true;
                    exist = true;
                    break;
                }
            }
 
            if(!exist && N % 2 == 0) flag = true;
            if(flag) cnt++;
        }

        cout<<cnt<<endl;
    }

    return 0;
}
