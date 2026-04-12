#include <bits/stdc++.h>
using namespace std;
long int getTaroScore(long int start, long int end, long int sum, vector<long int> &elem, vector<vector<long int> > &score) {
    if (start == end)
        return elem[start];
    if (start+1 == end)
        return max (elem[start], elem[end]);
    if (score[start][end] != -1)
        return score[start][end];
    long int left = sum - getTaroScore(start+1, end, sum-elem[start], elem, score);
    long int right = sum - getTaroScore(start, end-1, sum-elem[end], elem, score);
    return score[start][end] = max (left, right);
}
int main() {
    long int n;
    cin>>n;
    long int sum = 0;
    vector<long int> elem(n);
    for (long int i = 0; i < n; i++) {
        cin>>elem[i];
        sum += elem[i];
    }
    vector<vector<long int> > score(n, vector<long int>(n, -1) );
    long int start = 0, end = n-1;
    long int taroScore = getTaroScore(start, end, sum, elem, score);
    long int jiroScore = sum - taroScore;
    cout<<taroScore - jiroScore<<"\n";
    return 0;
}
