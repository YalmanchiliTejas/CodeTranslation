#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long int lli;
bool comp(const vector<pair<lli, lli> > &a, const vector<pair<lli, lli> > &b){
    return a.size() < b.size();
}

int main(){
    int n;
    lli a,b;
    cin >> n >> a >> b;
    vector<vector<pair<lli, lli> > > wv(5);
    for(int i=0; i<n; i++){
        lli t,x,y;
        cin >> t >> x >> y;
        t--;
        wv[t].push_back(make_pair(x, y));
    }
    sort(wv.begin(), wv.end(), comp);
    for(int i=0; i<5; i++){
        wv[i].push_back(make_pair(0, 0));
    }

    vector<pair<lli, lli> > en1, en2;
    for(int i=0; i<(int)wv[0].size(); i++){
        for(int j=0; j<(int)wv[1].size(); j++){
            for(int k=0; k<(int)wv[2].size(); k++){
                lli w = wv[0][i].first +wv[1][j].first +wv[2][k].first;
                lli v = wv[0][i].second +wv[1][j].second +wv[2][k].second;
                en1.push_back(make_pair(w, v));
            }
        }
    }
    for(int i=0; i<(int)wv[3].size(); i++){
        for(int j=0; j<(int)wv[4].size(); j++){
            lli w = wv[3][i].first +wv[4][j].first;
            lli v = wv[3][i].second +wv[4][j].second;
            en2.push_back(make_pair(w, v));
        }
    }
    sort(en1.begin(), en1.end());
    sort(en2.begin(), en2.end());

    bool yes = false;
    multiset<lli> validrange;
    int end = en2.size()-1;
    int begin = end; //逆半開
    for(int i=0; i<(int)en1.size(); i++){
        while(begin >= 0 && en2[begin].first +en1[i].first >= a){
            validrange.insert(en2[begin].second);
            begin--;
        }
        while(end > begin && en2[end].first +en1[i].first > b){
            validrange.erase(validrange.find(en2[end].second));
            end--;
        }
        auto itr = validrange.lower_bound(a -en1[i].second);
        if(itr != validrange.end() && *itr +en1[i].second <= b){
            yes = true;
            break;
        }
    }

    if(yes){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
