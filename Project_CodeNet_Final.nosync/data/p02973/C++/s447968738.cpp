#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    //各部分増加列の最大値を格納

    vector<int> l;
    l.push_back(A[N-1]);
    for(int i=N-2 ; i>=0; i--){

        //一番でかいやつ以上なら、新たに部分草加列を作成
        if(A[i] >= l[l.size()-1]){
            l.push_back(A[i]);
            continue;
        }else if(A[i] < l[0]){
            l[0] = A[i];
            continue;
        }

        //追加可能な中で一番最小値の小さい部分増加列に追加
        auto it = upper_bound(l.begin(), l.end(), A[i]);
        *it = A[i];
    }

    cout << l.size();

    return 0;
}