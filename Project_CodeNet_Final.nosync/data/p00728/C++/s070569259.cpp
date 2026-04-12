#include<bits/stdc++.h>
using namespace std;

//constant
const int inf=1<<28;

//variable
int n;
int in;
int maxi=-inf;
int mini=inf;
int sum;


int main(){

    while(cin>>n, n){
        sum=0;
        maxi=-inf;
        mini=inf;
        for(int i=0; i<n; i++){
            cin>>in;
            maxi=max(in,maxi);
            mini=min(in,mini);
            sum+=in;
        }
        //out<<maxi<<' '<<mini<<endl;
        cout<<(int)(((sum-maxi-mini)*1.0)/(n-2))<<endl;
    }

    return 0;
}