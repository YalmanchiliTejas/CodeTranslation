#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007


class Graph {
    int V;
    vector<list<int>> edges;
    public:
    Graph(int nodes){
        V = nodes;
        edges.resize(nodes + 1);
    }
    void addEdge(int from, int to){
        edges[from].push_back(to);
    }
    int min_dist(int &fin, int i, map<int ,bool> &special, vector<bool> &check){
        check[i] = true; 
        multiset<int> ms;     
        int k;
        for(auto it = edges[i].begin(); it != edges[i].end(); it++){
            if(check[*it] == true)
                continue;
            k = min_dist(fin, *it, special, check);
            if(k != 0)
                ms.insert(k);
        }
        for(auto it = ms.begin(); it != ms.end(); it++){
            fin += (*it);
            //cout << *it << " ";
        }
        //cout << endl;
        if(ms.size() % 2 == 0){
            if(special[i])    
                return 1;
            return 0;
        }
        else{
            if(special[i])
                return 0;
            auto it = ms.begin();
            fin -= (*it);
            return (*it) + 1;
        }
    }
};


int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll sum = 0;
        ll temp = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            sum = (sum + (arr[i] % INF)*(temp % INF)) % INF;
            temp =  (temp + arr[i])  % INF;
        }
        
        
        cout << sum % INF << endl;
    }
    return 0;
}





