#include <bits/stdc++.h>
#define maxn 200002
using namespace std;
int main(){
    map<int,int>x;
    int n,temp;
    cin>>n;
    vector<int> arr;
    vector<int> brr;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    brr=arr;
    sort(arr.begin(),arr.end());
    int a ,b;
    for(int i=0;i<n;i++){
        if(brr[i]<arr[n/2]){
            cout<<arr[n/2]<<"\n";
        }
        else{
            cout<<arr[n/2-1]<<"\n";
        }
    }    
}