#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    int maxh=v[0];
    int cnt=1;
    for(int i=1; i<n; i++){
        if(v[i]>=maxh){
            cnt++;
            maxh=v[i];
        }
    }
    
    cout<<cnt<<endl;
}
