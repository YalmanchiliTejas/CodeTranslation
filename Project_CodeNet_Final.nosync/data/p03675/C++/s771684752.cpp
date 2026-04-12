#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    list<long long> b;
    for(int i{};i<n;++i){
        long long a;
        cin>>a;
        if(i%2)b.push_front(a);
        else b.push_back(a);
    }
    if(n%2){
        cout<<*b.rbegin();
        for(auto p=next(b.rbegin(),1);p!=b.rend();++p)
            cout<<' '<<*p;
    }
    else{
        cout<<*b.begin();
        for(auto p=next(b.begin(),1);p!=b.end();++p)
            cout<<' '<<*p;
    }
    cout<<endl;
}