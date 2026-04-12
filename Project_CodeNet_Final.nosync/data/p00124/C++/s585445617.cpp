#include <tuple>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef tuple<string,int> Ttype;

template<int id> class CompTupleBy{
public:
    template<class T>
    bool operator()(const T& a,const T& b) const{
        return get<id>(a) > get<id>(b);
    }
};


int main(){
    int n,w=-1,l,d;
    string s;
    vector<Ttype> v;

    while(cin>>n,n){
        if(w!=-1) cout<<endl;
        for(int i=0;i<n;i++){
            cin>>s>>w>>l>>d;
            cin.ignore();
            v.push_back(Ttype(s,3*w+d));
        }

        stable_sort(v.begin(),v.end(),CompTupleBy<1>());

        for(auto t:v){
            cout<<get<0>(t)<<","<<get<1>(t)<<endl;
        }

        v.clear();
    }

    return 0;
}