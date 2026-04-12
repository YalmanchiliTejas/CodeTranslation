#include <iostream>
#include <deque>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

int main(){
    int n,num;
    cin >> n;
    deque<int> dq;
    rep(i,n){
        cin >> num;
        if(((i+n) % 2 )!= 0){
            dq.push_front(num);
        }else{
            dq.push_back(num);
        }
    }
    for(auto itr = dq.begin(); itr != dq.end(); ++itr){
        cout << *itr << endl;
    }

    return 0;
}