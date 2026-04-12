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
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    int N;cin>>N;
    string S;cin>>S;
    int a[100010];
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            a[0]=i,a[1]=j;
            for(int k=2;k<=N;k++){
                if(a[k-1]==0){
                    if(S[k-1]=='o')a[k]=a[k-2];
                    else           a[k]=1-a[k-2];
                }
                else{
                    if(S[k-1]=='o')a[k]=1-a[k-2];
                    else           a[k]=a[k-2];
                }
            }
            int a_N;
            if(a[0]==0){
                if(S[0]=='o')a_N=a[1];
                else         a_N=1-a[1];
            }
            else{
                if(S[0]=='o')a_N=1-a[1];
                else         a_N=a[1];
            }

            if(a[N-1]==a_N && a[0]==a[N]){
                for(int l=0;l<N;l++){
                    if(a[l]==0)cout<<"S";
                    else       cout<<"W";
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}