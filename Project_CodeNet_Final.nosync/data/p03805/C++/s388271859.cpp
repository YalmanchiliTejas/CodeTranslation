#include<bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int res=0;
int N, M;
vector <pii> ab;

bool all_flag(bool flag[]){
        for(int i=0;i<N;i++){
                if(!flag[i]){
                        return false;
                }
        }
        return true;
}

void rec(int n, bool flag[]){
        if(all_flag(flag)){
                res++;
                return;
        }
        for(int i=0;i<M;i++){
                if(n==ab[i].first&&!flag[ab[i].second-1]){
                        flag[ab[i].second-1]=true;
                        rec(ab[i].second, flag);
                        flag[ab[i].second-1]=false;
                }
                else if(n==ab[i].second&&!flag[ab[i].first-1]){
                        flag[ab[i].first-1]=true;
                        rec(ab[i].first, flag);
                        flag[ab[i].first-1]=false;
                }
        }
}

int main(){
        cin>>N;
        cin>>M;
        for(int i=0;i<M;i++){
                int aa, bb;
                cin>>aa>>bb;
                if(bb>aa){
                        swap(aa, bb);
                }
                ab.push_back(make_pair(aa, bb));
        }
        sort(ab.begin(), ab.end());
        bool flag[8];
        for(int i=0;i<8;i++){
                flag[i]=false;
        }
        flag[0]=true;
        rec(1, flag);
        cout<<res<<endl;
        return 0;
}
