#include <bits/stdc++.h>
using namespace std;
int main(void) {
    std::deque<int> number;
    std::deque<int> numtoscore;
    std::deque<int> score;
    int p,s,q;
    while (scanf("%d,%d",&p,&s)) {
        if (p==0 && s==0) {
            break;
        } else {
            number.emplace_back(p);
            numtoscore.emplace_back(s);
            auto itr = find(score.begin(),score.end(),s);
            if (*itr==0) {
                score.emplace_back(s);
            }
        }
    }
    sort(score.begin(),score.end(),greater<int>());
    while (cin>>q) {
        auto itr2 = find(number.begin(),number.end(),q);
        int hoge = numtoscore[*itr2-1];
        for (int i=0;i<score.size();i++) {
            if (score[i]==hoge) {
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
