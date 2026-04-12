#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_N 100001
using namespace std;
typedef long long ll;

ll a_seq[MAX_N];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a_seq[i];
    vector<ll> large_element, small_element;
    sort(a_seq, a_seq + N);
    ll min_a = a_seq[0];
    int large_idx = N - 1, small_idx = 1;
    while (large_idx >= small_idx) {
        large_element.push_back(a_seq[large_idx]);
        large_idx--;
        if (large_idx < small_idx || large_idx < 0) break;
        large_element.push_back(a_seq[large_idx]);
        large_idx--;
        if (small_idx > large_idx || small_idx > N - 1) break;
        small_element.push_back(a_seq[small_idx]);
        small_idx++;
        if (small_idx > large_idx || small_idx > N - 1) break;
        small_element.push_back(a_seq[small_idx]);
        small_idx++;
    }

    /*
    cout << "---------" << endl;
    for (int i = 0; i < small_element.size(); i++) cout << small_element[i] << ' ';
    cout << endl;
    for (int i = 0; i < large_element.size(); i++) cout << large_element[i] << ' ';
    cout << endl;
    cout << "---------" << endl;
    */

    ll ans = 0, left_a = min_a, right_a = min_a;
    for (int i = 0; i < large_element.size(); i += 2) {
        // cout << left_a << " -> ";
        ans += abs(left_a - large_element[i]);
        left_a = large_element[i];
        if (i < small_element.size()) {
            // cout << left_a << " -> ";
            ans += abs(left_a - small_element[i]);
            left_a = small_element[i];
        }
        else break;
    }
    // cout << left_a << endl;
    for (int i = 1; i < large_element.size(); i += 2) {
        // cout << right_a << " -> ";
        ans += abs(right_a - large_element[i]);
        right_a = large_element[i];
        if (i < small_element.size()) {
            // cout << right_a << " -> ";
            ans += abs(right_a - small_element[i]);
            right_a = small_element[i];
        }
        else break;
    }
    // cout << right_a << endl;

    // 最大の場合
    large_element.clear();
    small_element.clear();
    reverse(a_seq, a_seq + N);
    ll max_a = a_seq[0];
    large_idx = N - 1, small_idx = 1;
    while (large_idx >= small_idx) {
        large_element.push_back(a_seq[large_idx]);
        large_idx--;
        if (large_idx < small_idx || large_idx < 0) break;
        large_element.push_back(a_seq[large_idx]);
        large_idx--;
        if (small_idx > large_idx || small_idx > N - 1) break;
        small_element.push_back(a_seq[small_idx]);
        small_idx++;
        if (small_idx > large_idx || small_idx > N - 1) break;
        small_element.push_back(a_seq[small_idx]);
        small_idx++;
    }

    ll now_ans = 0; 
    left_a = max_a, right_a = max_a;
    for (int i = 0; i < large_element.size(); i += 2) {
        now_ans += abs(left_a - large_element[i]);
        left_a = large_element[i];
        if (i < small_element.size()) {
            now_ans += abs(left_a - small_element[i]);
            left_a = small_element[i];
        }
        else break;
    }
    for (int i = 1; i < large_element.size(); i += 2) {
        now_ans += abs(right_a - large_element[i]);
        right_a = large_element[i];
        if (i < small_element.size()) {
            now_ans += abs(right_a - small_element[i]);
            right_a = small_element[i];
        }
        else break;
    }

    if (ans < now_ans) ans = now_ans;
    cout << ans << endl;
    return 0;
}