#include <iostream>
#include <vector>

using namespace std;
template<class T> inline bool chmax(T &a, T b){ if(a < b){a = b; return true;} return false;}

struct Edge{
    int to,weight;
    Edge(int t,int w) : to(t), weight(w){}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

class Tree{
    public:
        Tree(int size) : mGraph(size), mMemo(size) {}
        void add_edge(int s, int t, int w = 1){
            mGraph[s].emplace_back(t,w);
            mGraph[t].emplace_back(s,w);
        }

        // diameter of a tree
        pair<int,int> dfs(int v, int pv){
            pair<int,int> ret(0,v);
            for(Edge nv : mGraph[v]){
                if(nv.to == pv) continue;
                pair<int,int> tmp = dfs(nv.to,v);
                if(chmax(ret.first,tmp.first + nv.weight)){
                    ret.second = tmp.second;
                }
            }
            return ret;
        }

        int diameter(){
            pair<int,int> s = dfs(0,-1);
            pair<int,int> t = dfs(s.second,-1);
            return t.first;
        }
        //

        // height of a tree
        int dfs_memo(int v,int e){
            if(mMemo[v][e].weight >= 0) return mMemo[v][e].weight;
            mMemo[v][e].weight = mGraph[v][e].weight;
            int nv = mMemo[v][e].to;
            for(int ne = 0; ne < mMemo[nv].size(); ++ne){
                if(mMemo[nv][ne].to == v) continue;
                mMemo[v][e].weight = max(mMemo[v][e].weight, dfs_memo(nv,ne) + mGraph[v][e].weight);
            }
            return mMemo[v][e].weight;
        }

        vector<int> height(){
            mMemo = mGraph;
            // init memo
            for(int i = 0; i < mMemo.size(); ++i){
                for(int j = 0; j < mMemo[i].size(); ++j){
                    mMemo[i][j].weight = -1;
                }
            }
            //
            for(int i = 0; i < mMemo.size(); ++i){
                for(int j = 0; j < mMemo[i].size(); ++j){
                    if(mMemo[i][j].weight < 0){
                        mMemo[i][j].weight = dfs_memo(i,j);
                    }
                }
            }

           // calc result
           vector<int> ret(mMemo.size());
           for(int i = 0; i < mMemo.size(); ++i){
               for(int j = 0; j < mMemo[i].size(); ++j){
                   ret[i] = max(ret[i],mMemo[i][j].weight);
               }
           }
           return ret;
        }

    private:
        Graph mGraph;
        Graph mMemo;
};

int main(){
    int n,s,t,w;
    cin >> n;
    Tree tree(n);
    for(int i = 0; i < n-1; ++i){
        cin >> s >> t >> w;
        tree.add_edge(s,t,w);
    }
    auto ret = tree.height();
    for(int r : ret) cout << r << '\n';
    return 0;
}
