#include<bits/stdc++.h>
using namespace std;

vector<long long> meat_num(51, 1);
vector<long long> all_num(51, 1);

long long solve(int y, long long z){
    if (z == all_num[y]) return meat_num[y];
    if (z <= 1) return 0;
    if (z <= all_num[y - 1] + 1) return solve(y - 1, z - 1);
    return meat_num[y - 1] + 1 + solve(y - 1, z - all_num[y - 1] - 2); 
}

int main(){
    int n; long long x;
    cin >> n >> x;
    for (int i = 0; i < 50; i++) meat_num[i + 1] = meat_num[i] * 2 + 1;
    for (int i = 0; i < 50; i++) all_num[i + 1] = all_num[i] * 2 + 3;
    cout << solve(n, x) << endl;
}