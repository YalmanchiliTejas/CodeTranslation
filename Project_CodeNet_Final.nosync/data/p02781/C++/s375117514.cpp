//ABC154E.cpp
#include <bits/stdc++.h>
using namespace std;

//コンビネーションの計算
long long com(long long N, long long R) {
    if (R < 0 || R > N) return 0;
    if (R == 1) return N;
    else if (R == 2) return N * (N-1) / 2;
    else return N * (N-1) * (N-2) / 6;
}

long long pow(long long N, long long k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) res *= N;
    return res;
}

string S;
int N, K;

//i桁目を調査中、0以外の数を後k個使える、smaller==1ならもう解が分かる
long long solve(int i, int k, int smaller) {
    if (i == N) { //N桁目(最後)までいったとき
        if (k == 0) return 1; //ちょうど終われば
        else return 0; //ちょうど終わらなければ
    }
    if (k == 0) return 1; //残り桁全部0なので1通り
    
    if (smaller){ //既に小さいことが確定
    	//残りN-i桁の内、k桁が0以外なので[9のk乗*(N-i)Ck]
    	return com(N-i, k) * pow(9, k);
    }
    else { //i桁目までが最大値と一致している時
    	//最大値のi桁目が0なら、i桁目は0一択で、最大値と一致してるので次の桁へ
        if (S[i] == '0') return solve(i+1, k, false);
        else { //最大値のi桁目が0以外なら
        	//i桁目が0か、最大値と一致してるか、その間の数か
        	//i桁目が0のとき最大値のi桁目は0出ないのでsmaller
            long long zero = solve(i+1, k, true);
            //i桁目が間の時最大値より確実に小さく、以降の桁で使える0以外の数が1減る
            long long aida = solve(i+1, k-1, true) * (S[i] - '1');
            //i桁目が最大値と一致するときsmallerか分からない
            long long icchi = solve(i+1, k-1, false);
            return zero + aida + icchi;
        }
    }
}

int main() {
    cin >> S >> K;
    N = S.size();
    cout << solve(0, K, false) << endl;
}