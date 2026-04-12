#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,k,l,m,n;
    vector<long long int>v,v1;
    cin>>n;
    v.clear();
    for(i=0;i<n;i++){
        cin>>j;
        v.push_back(j);
    }
    if(n%2==0){
    for(k=n-1;k>=0;k-=2){
            cout<<v[k]<<" ";
        }
    for(l=0;l<n-2;l+=2){cout<<v[l]<<" ";}
        cout<<v[n-2]<<endl;
      }
   else if(n%2==1&&n!=1){
    for(k=n-1;k>=0;k-=2){
            cout<<v[k]<<" ";
        }
    for(l=1;l<n-2;l+=2){cout<<v[l]<<" ";}
        cout<<v[n-2]<<endl;
        }
    else{cout<<v[0]<<endl;}
    
}