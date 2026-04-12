#include <bits/stdc++.h>
using namespace std;
int max(vector<int> &a,int b){
    vector<int> hh(b);
    for(int i=0;i<b;i++){
        hh[i]=a[i];
    }
    sort(hh.begin(),hh.end());
    reverse(hh.begin(),hh.end());
    return hh[0];
}

int main(){
    int n,m;
    m=1;
    cin >> n;
    vector <int>h(n);
    for(int i=0;i<n;i++){
        cin >> h.at(i);
    } 
    for(int i=0;i<n-1;i++){
        if(max(h,i+1)<= h[i+1]) m++; 
        //cout << i << endl;;
    } 
    
    cout << m << endl;

}