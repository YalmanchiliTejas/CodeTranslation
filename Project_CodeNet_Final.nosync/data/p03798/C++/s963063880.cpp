#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
#define INT long long int
#define REP(i,n) for(int(i)=0;(i)<(n);(i)++) 
using namespace std;
const long long INF = numeric_limits<long long>::max();


int main()
{
    int N;
    string S;
    cin>>N;
    cin>>S;
    bool ans[N];
    bool flag = false;
    for (int i=0;i<4;i++){
        flag = false;
        REP(j,N) ans[i]=false;
        REP(j,2){
            if ((i>>j)%2==1) ans[j] = true;
            else ans[j] = false;
        }
        if (S[0]=='o') ans[N-1] = ((ans[0]^ans[1]));
        else ans[N-1] = !(ans[0]^ans[1]);

        for (int j=1;j<N-1;++j){
            if (j==N-2){
                        
                bool tmp;
                if (S[j]=='o'){
                    tmp = ans[j-1]^ans[j];
                }else{
                    tmp = !(ans[j-1]^ans[j]);
                }
                if (tmp!=ans[N-1]){
                    flag = true;
                    break;
                }
            }else{
                bool tmp;
                if (S[j]=='o'){
                    ans[j+1] = ans[j-1]^ans[j];
                }else{
                    ans[j+1] = !(ans[j-1]^ans[j]);
                }
            }
            
        }
        if (flag) continue;
        bool tmp;
        if (S[N-1]=='o'){
            tmp = ans[N-1]^ans[N-2];
        }else{
            tmp = !(ans[N-1]^ans[N-2]);
        }
        if (tmp!=ans[0]){
            continue;
        }
        
        if (S[0]=='o'){
            tmp = ans[N-1]^ans[0];
        }else{
            tmp = !(ans[N-1]^ans[0]);
        }
        if (tmp!=ans[1]){
            continue;
        }
            
        for (int i=0;i<N;i++){
             if (!ans[i]) cout<<'S';
             else cout<<'W';
        }
        cout<<endl;
        return 0;
    }
    cout <<-1<<endl;

    return 0;
}