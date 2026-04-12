#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#ifdef ONLINE_JUDGE
#define D(...)
#else
#define D(...)cerr<<__LINE__<<":"<<"["<<#__VA_ARGS__<<"]->",P(__VA_ARGS__)
#endif
void P(){cerr<<endl;} 
template<typename H,typename...T>void P(H h,T...t){cerr<<h<<" ";P(t...);}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    int arr[n][m] {};
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            char x;cin>>x;
            if(x=='#')
                arr[i][j]=1;
        }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(arr[i][j]==1)goto label1;
        }
        for(int j=0;j<m;++j)
            arr[i][j]=-1;
        label1:;
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(arr[j][i]==1)goto label2;
        }
        for(int j=0;j<n;++j)
            arr[j][i]=-1;
        label2:;
    }
    for(int i=0;i<n;++i){
        int flag=0;
        for(int j=0;j<m;++j)
            if(arr[i][j]!=-1){
                flag=1;
                if(arr[i][j])
                    cout<<'#';
                else cout<<'.';
            }
        if(flag==1)cout<<endl;
    }

}