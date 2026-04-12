#include <iostream>
#include <set>
using namespace std;
int main(void){
    int n, s[100000], cand;
    long long score_max = 0, score_tmp;
    set<int> used;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=1;i<n;i++){
        score_tmp = 0;
        used.clear();
        for(int j=1; i*j<n-1-i; j++){
            cand = i*j;
            if(used.find(cand) != used.end())break;
            used.insert(cand);
            score_tmp += s[cand];

            cand = n-1-i*j;
            if(used.find(cand) != used.end())break;
            used.insert(cand);
            score_tmp += s[cand];

            score_max = max(score_max, score_tmp);
        }
    }
    cout << score_max << endl;
}
