#include<bits/stdc++.h>
using namespace std;
#define lli long long int 
lli maxi(lli a,lli b){
    if(a>=b)return a;
    return b;
}
lli mini(lli a,lli b){
    if(a<=b)return a;
    return b;
}

int main(){
    int n,k;
    cin>>n;
    vector<lli> arr(n,0);
    lli sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
        //cout<<arr[i]<<endl;
        
    }
     
    lli table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            lli x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            lli y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            lli z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = maxi(arr[i] + mini(x, y), arr[j] + mini(y, z)); 
        } 
    } 
  
     lli fs =table[0][n - 1]; 
    //cout<<fs<<endl;
    sum=sum-fs;
    cout<<fs-sum<<endl;
}