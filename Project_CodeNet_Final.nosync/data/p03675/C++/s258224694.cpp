#include <iostream>
#include <list>
#include <queue>

using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    int mod2 = N%2;
    list<ll> lst;
    for(int i=1;i<=N;i++){
        int tmp;
        cin >> tmp;
        if(i%2==mod2){
            lst.push_front(tmp);
        }else{
            lst.push_back(tmp);
        }
    }

    for(auto itr=lst.begin();itr!=lst.end();++itr){
        cout << *itr << " ";
    }
    cout << endl;
    return 0;

}