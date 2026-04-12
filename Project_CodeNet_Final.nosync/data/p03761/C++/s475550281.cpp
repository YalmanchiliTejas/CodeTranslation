#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>

const int MOD = pow(10,9)+7;
typedef long long ll;

using namespace std;
int in(){
    int temp;
    scanf("%d",&temp);
    return temp;
}

ll lin(){
    ll temp;
    scanf("%lld",&temp);
    return temp;
}


int main() {

    int N  = in();
    
    string S[N+1];
    
    for(auto i = 0; i<N; i++){
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }
    
    string out;
    
    char maxim = '!';
    
    while(1){
        
        for(auto i = 0; i<N; i++){
            if (S[i].size()==0){
                cout << out << endl;
                return 0;
            }
        }
        
        for(auto j = 0; j <N; j++){  ///頭揃えする。
            while(S[j].front() < maxim){  //// 辞書順最大のものに揃うまで先頭から消していく。
                
                S[j].erase(S[j].begin());
                
                if(S[j].size() == 0){   ///どれかが空になったら終了。
                    cout << out << endl;
                    return 0;
                }
            }
            
            /// この段階で、Sはbcccのような形。bを削除したい。
            /// cが現れた時点で最大値をそれに更新する。
            
            if (S[j].front() > maxim){
                maxim = S[j].front();
            }
        }
        
        int count = 0;
        for(auto i = 0; i <N; i++){
            count += (maxim == S[i].front());
        }
        
        if (count == N){
            for(auto i = 0; i <N; i++){
                
                if (S[i].size() == 0){
                    cout << out << endl;
                    return 0;
                }
                S[i].erase(S[i].begin());
            }
            out.push_back(maxim);
        }
        
    }
    

    
    return 0;
    
}


