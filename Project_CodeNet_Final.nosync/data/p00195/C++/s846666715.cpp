#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define P pair<int, char>

int main(){
    int tmp1, tmp2;
    while(cin >>tmp1 >>tmp2){
        if(tmp1 == 0 && tmp2 == 0) break;
        vector<P> vec;
        char shop[5] = {'A', 'B', 'C', 'D', 'E'};
        vec.push_back( make_pair(tmp1 + tmp2, shop[0]) );
        for(int i = 1; i < 5; i++){
            cin >>tmp1 >>tmp2;
            vec.push_back( make_pair(tmp1 + tmp2, shop[i]) );
        }
        sort(vec.begin(), vec.end());
        cout <<vec[vec.size() - 1].second <<" " <<vec[vec.size() - 1].first <<endl;
    }
    return 0;
}