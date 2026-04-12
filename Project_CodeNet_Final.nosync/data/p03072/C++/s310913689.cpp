#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

int main(void){

    int n;
    cin>>n;
    int r = 1;
    int max;

    vector<int> v;
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        v.push_back(h);
    }
    
    max = v[0];

    for(int i=1;i<n;i++){
        if(max <= v[i]){
            max = v[i];
            r++;
        }
    }

    cout<<r<<endl;

    return 0;
}