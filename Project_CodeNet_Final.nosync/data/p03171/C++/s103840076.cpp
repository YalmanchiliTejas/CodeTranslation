// Deque.cpp
// https://atcoder.jp/contests/dp/tasks/dp_l

#include <iostream>
#include <cstring>
using namespace std;
typedef  long long int llu;

llu N;
llu arr[3000];

pair<llu, llu> memoTable[3000][3000][2];
bool isComputed[3000][3000][2];

pair<llu, llu> score(llu i, llu j, bool isTaroTurn = 1){


    if(i > j){
        return make_pair(0, 0);
    }

    if(i == j){
        if(isTaroTurn)
            return make_pair(arr[i], 0);
        return make_pair(0, arr[i]);
    }

    if(isComputed[i][j][isTaroTurn]){
        return memoTable[i][j][isTaroTurn];
    }

    isComputed[i][j][isTaroTurn] = 1;

    if(isTaroTurn){

        pair<llu, llu> p1 = score(i+1, j, !isTaroTurn);
        p1.first += arr[i];

        pair<llu, llu> p2 = score(i, j-1, !isTaroTurn);
        p2.first += arr[j];

        if(p1.first - p1.second > p2.first - p2.second){
            memoTable[i][j][isTaroTurn] = p1;
            return p1;
        }
        memoTable[i][j][isTaroTurn] = p2;
        return p2;

    }
    else{

        pair<llu, llu> p1 = score(i+1, j, !isTaroTurn);
        p1.second += arr[i];

        pair<llu, llu> p2 = score(i, j-1, !isTaroTurn);
        p2.second += arr[j];

        if(p1.first - p1.second < p2.first - p2.second){
            memoTable[i][j][isTaroTurn] = p1;
            return p1;
        }
        memoTable[i][j][isTaroTurn] = p2;
        return p2;
    }

}

int main(){

    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); cout<<"Deque.cpp\n";
    
    memset(isComputed, 0, sizeof(isComputed));

    cin >> N;
    for(llu i=0; i<N; ++i){
        cin >> arr[i];
    }

    pair<llu, llu> p = score(0, N-1);
    cout<<(p.first - p.second);

    return 0;
}

