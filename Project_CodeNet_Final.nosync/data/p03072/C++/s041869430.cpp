#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    vector<int> max(n,0);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(0==i){
            max[i]=h[i];
            cnt++;
            
        }else{
            if(max[i-1]<=h[i]){
                cnt++;
                max[i]=h[i];
            }else{
                max[i]=max[i-1];
            }
        }
    }
    
    cout<<cnt<<endl;
    return 0;
}