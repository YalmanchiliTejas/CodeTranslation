#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, n) for(int i=(a); i<(n); i++)
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;

int main(){
    int N; cin >> N;
    /*vl A(N);
    REP(i, N){
        cin >> A[i];
    }*/
    vl max;
    int A;
    cin >> A;
    max.push_back(-A);
    FOR(i, 1, N){
        int tmp;
        cin >> tmp;
        bool isIn = false;
        int num = max.size();
        if(-max[num-1] >= tmp){
            max.push_back(-tmp);
            continue;
        }
        REP(j, num){
            if(-max[j] < tmp){
                max[j] = -tmp;
                isIn = true;
                break;
            }
        }
        if(!isIn) max.push_back(-tmp);
    }
    cout << max.size() << endl;
    return 0;
}