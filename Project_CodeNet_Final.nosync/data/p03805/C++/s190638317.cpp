#include<vector>
#include<iostream>
#include<numeric>

using namespace std;



int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > em(N, vector<int>(N, 0));
    int t1, t2;
    for(int i=0; i!=M; i++){
        cin >> t1 >> t2;
        em.at(t1-1).at(t2-1)++;
        em.at(t2-1).at(t1-1)++;
    }
    
    int out = 0;
    vector<int> lv(N);
    iota(lv.begin(), lv.end(),0);
    vector<vector<int> > lvl;
    lvl.push_back(lv);

    while(!lvl.empty()){
        vector<int> clv = lvl.back();
        lvl.pop_back();
        if(clv.size()==1) out ++;
        int pos = clv.front();
        for(int i=1; i!= clv.size(); i++){
            if(em.at(pos).at(clv.at(i))){
                vector<int> newlv(clv);
                newlv.erase(newlv.begin() + i);
                newlv.at(0) = clv.at(i);
                lvl.push_back(newlv);
            }
        }
    }
    cout << out << endl;
    return 0;
    
}