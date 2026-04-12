#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    list<long long> b;
    // vector<long long> a;
    long long n,tmp;
    cin >> n;
    for(long long i = 0; i<n;i++){
        cin >> tmp;
        if(i%2 == 0){
            b.push_front(tmp);
        } else {
            b.push_back(tmp);
        }
    }
    if(n%2 == 0)
        reverse(b.begin(),b.end());
    for(auto it = b.begin();it!= b.end();it++){
        if(it == b.begin()){
            cout << *it;
        }else{
            cout << ' ' << *it;
        }
    }
    cout << endl; 
    return 0;
}
