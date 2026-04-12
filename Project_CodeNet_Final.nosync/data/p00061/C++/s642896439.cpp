#include<iostream>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

int main(){
    vector<int>vec;
    set<int>s;
    int t,n;
    char c;
    while(cin>>t>>c>>n){
        if(t==0&&n==0)break;
        vec.push_back(n);
        s.insert(n);
    }
    while(cin>>t){
        long a=s.size()-distance(s.begin(),s.find(vec[t-1]));
        cout<<a<<endl;
    }
}