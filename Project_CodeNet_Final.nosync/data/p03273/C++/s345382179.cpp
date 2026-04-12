#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 2e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    int n,m;
    cin>>n>>m;
    string arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    bool row[n]={};
    bool col[m]={};
    for(int i=0;i<n;i++){
        bool temp=true;
        for(int j=0;j<m;j++){
            if(arr[i][j]=='#')temp=false;
        }
        row[i]=temp;
    }
    for(int j=0;j<m;j++){
        bool temp=true;
        for(int i=0;i<n;i++){
            if(arr[i][j]=='#')temp=false;
        }
        col[j]=temp;
    }
    bool nl;
    for(int i=0;i<n;i++){
        nl=false;
        for(int j=0;j<m;j++){
            if(row[i]||col[j])continue;
            else {
                cout<<arr[i][j];
                nl=true;
            }
        }
        if(nl)
        cout<<endl;
    }
}