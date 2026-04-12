#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
        int n,m,i,t1,t2,cnt=0,flg=0;
        cin >> n >> m;
        vector<vector<int>> r(n);
        vector<int> idx(n);
        for(i=0;i<n;++i){
                idx.at(i) = i;
        }
        for(i=0;i<m;++i){
                cin >> t1 >> t2;
                --t1; --t2;
                r.at(t1).push_back(t2);
                r.at(t2).push_back(t1);
        }
        do{
                if(idx.at(0)!=0) continue;
                else{
                        for(i=0;i<n-1;++i){
                                if(find(r.at(idx.at(i)).begin(), r.at(idx.at(i)).end(), idx.at(i+1))==r.at(idx.at(i)).end()){
                                        flg = 1;
                                        break;
                                }
                        }
                        if(flg==0) ++cnt;
                        flg = 0;
                }
        }while(next_permutation(idx.begin(), idx.end()));
        cout << cnt << endl;
        return 0;
}