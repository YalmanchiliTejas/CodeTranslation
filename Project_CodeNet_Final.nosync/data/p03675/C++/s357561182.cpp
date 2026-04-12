#include <iostream>
#include <list>
#include <queue>

using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    int mod2 = N%2;
    deque<ll> dq;
    for(int i=1;i<=N;i++){
        int tmp;
        cin >> tmp;
        if(i%2==mod2){
            dq.push_front(tmp);
        }else{
            dq.push_back(tmp);
        }
    }

    for(int i=0;i<N;i++){
        cout << dq[i];
        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;

}