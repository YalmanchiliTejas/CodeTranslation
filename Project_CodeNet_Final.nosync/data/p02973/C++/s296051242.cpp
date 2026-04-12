#include<set>
#include<iostream>
using namespace std;

int N;

int main(){
    cin >> N;
    multiset<int> ends;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        // a未満の終端が見つからなかったとき
        if(ends.lower_bound(a) == ends.begin()){
            ends.insert(a);
        }else{// a未満の終端が見つかったとき
            ends.erase(--(ends.lower_bound(a)));
            ends.insert(a);
        }
    }
    cout << ends.size() << endl;
}
