#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool func(vector<int> v){
    int maxp=0;
    for (int i=0; i<v.size(); i++) {
        if(i*10<=maxp){
            maxp=max(maxp,v[i]+i*10);
        }
    }
    return 10*(v.size()-1)<=maxp;
}

int main(){
    int n;
    cin>>n;
    vector<int>d,u;
    for (int i=0; i<n; i++) {
        int x;
        cin>>x;
        d.push_back(x);
    }
    u=d;
    reverse(u.begin(), u.end());
    
    cout<<(func(d)&&func(u)?"yes":"no")<<endl;
}
