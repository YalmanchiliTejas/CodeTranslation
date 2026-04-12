#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n,r,l;
        cin>>n>>l>>r;
        if(n==0&&r==0&&l==0)break;
        vector<int>v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        int count=0,f=0;
        for(int x=l;x<=r;x++){
            f=0;
            for(int i=1;i<=n;i++){
                if(x%v[i]==0&&i%2==1){
                    f=1;
                    break;
                }
                else if(x%v[i]==0&&i%2==0){
                    f=2;
                    break;
                }
            }
            if(f==1)count++;
            else if(f==0&&n%2==0)count++;
        }
        cout<<count<<endl;
    }
}
