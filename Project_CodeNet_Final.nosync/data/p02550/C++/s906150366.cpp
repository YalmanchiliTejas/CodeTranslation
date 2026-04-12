#include <bits/stdc++.h>

using namespace std;

long long note[100000+1];

int main() {
    long long n, x, m;
    cin >> n >> x >> m;

    unordered_map<long long, long long> rems;

    long long sum = 0;
    note[0] = x;
    rems[note[0]] = 0;
    sum = x;
    long long start = -1, end = -1;
    for(long long i = 1; i < n; i++) {
        note[i] = (note[i-1] * note[i-1]) % m;
        if(rems.find(note[i]) == rems.end()) {
            rems[note[i]] = i;
        }else {
            start = rems[note[i]];
            end = i;
            break;
        }
        sum += note[i];
    }

    if(start == -1) {
        cout << sum << endl;
        return 0;
    }

    long long count = 0;
    for(long long i = start; i < end; i++) {
        count += note[i];
    }

    sum += ((n - end) / (end - start)) * count;
    long long rest = (n - end) % (end - start);

    for(long long i = 0; i < rest; i++) {
        sum += note[start+i];
    }

    cout << sum << endl;
}