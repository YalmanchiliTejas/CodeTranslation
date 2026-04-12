#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
using namespace std;
int n,ans;
string a;
signed main(){
    for(;;){
        cin>>n;
        if(n==0)break;
        ans=0;
        int dice[6]={1,2,3,4,5,6};
        for(int i=0;i<n;i++){
            cin>>a;
            if(a[0]=='N'){
                swap(dice[0],dice[1]);
                swap(dice[1],dice[5]);
                swap(dice[5],dice[4]);
                ans+=dice[0];
            }
            else if(a[0]=='E'){
                swap(dice[0],dice[3]);
                swap(dice[3],dice[2]);
                swap(dice[3],dice[5]);
                ans+=dice[0];
            }
            else if(a[0]=='S'){
                swap(dice[0],dice[1]);
                swap(dice[0],dice[5]);
                swap(dice[0],dice[4]);
                ans+=dice[0];
            }
            else if(a[0]=='W'){
                swap(dice[0],dice[2]);
                swap(dice[2],dice[5]);
                swap(dice[5],dice[3]);
                ans+=dice[0];
            }
            else if(a[0]=='R'){
                swap(dice[1],dice[2]);
                swap(dice[2],dice[4]);
                swap(dice[4],dice[3]);
                ans+=dice[0];
            }
            else if(a[0]=='L'){
                swap(dice[1],dice[2]);
                swap(dice[1],dice[3]);
                swap(dice[3],dice[4]);
                ans+=dice[0];
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}