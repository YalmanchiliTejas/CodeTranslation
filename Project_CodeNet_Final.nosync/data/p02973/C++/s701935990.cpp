#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<deque>

using namespace std;

int main(){
    int N; cin >> N;
    deque<int> q;
    for (int i = 0; i < N; i++){
        int a_i; cin >> a_i;
        if (i == 0){
            q.push_back(a_i);
            continue;
        }
        auto itr = lower_bound(q.begin(), q.end(), a_i);
        if (itr == q.begin()) q.push_front(a_i);
        else{
            --itr;
            *itr = a_i;
        }
    }
    cout << q.size() << endl;
}
