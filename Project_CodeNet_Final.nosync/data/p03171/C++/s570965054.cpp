#include<bits/stdc++.h>
#define ll long long int 

using namespace std;
int calc(unordered_set<int >mp){
    
    int Mex=0;
    while(mp.find(Mex)!=mp.end()){
        Mex+=1;
    }
    return(Mex);
}
int main(){
    int n,k;
    cin >>n;
    ll arr[3001];
    for(int i=0;i<n;i++) cin >> arr[i];
    //cout <<arr[0];
    ll ans[n+1][n+1];
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r){
                ans[l][r]=arr[l];
            }
            else{
                ans[l][r]=max(arr[l]-ans[l+1][r],arr[r]-ans[l][r-1]);
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout <<ans[i][j]<<" ";
        }
        cout <<endl;
    }*/
    cout <<ans[0][n-1]<<endl;
}

