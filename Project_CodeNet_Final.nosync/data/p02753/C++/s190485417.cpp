#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string nums;
    cin >> nums;
    int i=0;
    if(nums[i] == 'A' && nums[i+1] == 'A' && nums[i+2] == 'A'){
        cout<<"No"<<"\n";
    }
    else if(nums[i] == 'B' && nums[i+1] == 'B' && nums[i+2] == 'B'){
        cout<<"No"<<"\n";
    }
    else{
        cout<<"Yes"<<"\n";
    }
    return 0;
}