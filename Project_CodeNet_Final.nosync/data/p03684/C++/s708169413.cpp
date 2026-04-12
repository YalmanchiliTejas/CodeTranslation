#include<bits/stdc++.h>

#define INF 100000000

using namespace std;

class City{
public:
    int ID;
    int X, Y;

    bool operator<(const City &c) const{
        if(X < c.X){
            return true;
        }else if(X > c.X){
            return false;
        }else if(Y < c.Y){
            return true;
        }
        return false;
    }
};

bool cmp_Y(const City &a, const City &b){
    if(a.Y < b.Y){
        return true;
    }else if(a.Y > b.Y){
        return false;
    }else if(a.X < b.X){
        return true;
    }
    return false;
}

int edge_cost(City a, City b){
    return min(abs(a.X-b.X), abs(a.Y-b.Y));
}

class Edge{
public:
    int to, from;
    int cost;

    void set(int t, int f, long c){
        to = t;
        from = f;
        cost = c;
    }

    bool operator<(const Edge &e) const{
        if(cost < e.cost){
            return true;
        }
        return false;
    }

    bool operator==(const Edge &e) const{
        if(to == e.to && from == e.from && cost == e.cost){
            return true;
        }
        return false;
    }

    inline bool operator!=(const Edge& e) const{
        return !(*this == e);
    }
};


vector<int> vertex;

int root(int x) {
    if(vertex[x]<0){
        return x;
    }
    return vertex[x] = root(vertex[x]);
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y){
        return;
    }
    if(-vertex[x] < -vertex[y]){
        swap(x, y);
    }
    vertex[x] -= -vertex[y];
    vertex[y] = x;
}

bool same(int x, int y) {
    return root(x) == root(y);
}
int size(int x) {
    return -vertex[root(x)];
}


vector<City> cites;
vector<Edge> edges;

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(10);

    int N;
    cin>>N;
    cites.resize(N);
    for(int i=0; i<N; ++i){
        cin>>cites[i].X>>cites[i].Y;
        cites[i].ID=i+1;
    }

    vector<City> dummy = cites;
    sort(dummy.begin(), dummy.end());
    map<int, set<int> > X_to_city_ID;
    set<int> zero_set;
    for(int i=0; i<N; i++){
        if(X_to_city_ID.find(dummy[i].X) == X_to_city_ID.end()){
            X_to_city_ID.insert(make_pair(dummy[i].X, zero_set));
        }
        if(!(i>0 && dummy[i].X == dummy[i-1].X && dummy[i].Y == dummy[i-1].Y)){
            X_to_city_ID[dummy[i].X].insert(dummy[i].ID);
        }
    }

    Edge edge;
    int city1, city2;
    int dist, min_dist;
    for(auto key_x = X_to_city_ID.begin(); key_x != prev(X_to_city_ID.end()); ++key_x){
        for(auto itr_city1 = (key_x->second).begin(); itr_city1 != (key_x->second).end(); ++itr_city1){
            min_dist = INF;
            for(auto itr_city2 = (next(key_x)->second).begin(); itr_city2 != (next(key_x)->second).end(); ++itr_city2){
                dist = edge_cost(cites[(*itr_city1) -1], cites[(*itr_city2) -1]);
                if(dist < min_dist){
                    min_dist = dist;
                    city1 = *itr_city1;
                    city2 = *itr_city2;
                }
            }
            edge.set(city1, city2, min_dist);
            edges.push_back(edge);
        }

        for(auto itr_city1 = (key_x->second).begin(); itr_city1 != prev((key_x->second).end()); ++itr_city1){
            edge.set(*itr_city1, *next(itr_city1), edge_cost(cites[(*itr_city1) -1], cites[*next(itr_city1) -1]));
            edges.push_back(edge);
        }
    }
    X_to_city_ID.clear();

    dummy = cites;
    sort(dummy.begin(), dummy.end(), cmp_Y);
    map<int, set<int> > Y_to_city_ID;
    for(int i=0; i<N; i++){
        if(Y_to_city_ID.find(dummy[i].Y) == Y_to_city_ID.end()){
            Y_to_city_ID.insert(make_pair(dummy[i].Y, zero_set));
        }
        if(!(i>0 && dummy[i].Y == dummy[i-1].Y && dummy[i].X == dummy[i-1].X)){
            Y_to_city_ID[dummy[i].Y].insert(dummy[i].ID);
        }
    }

    for(auto key_y = Y_to_city_ID.begin(); key_y != prev(Y_to_city_ID.end()); ++key_y){
        for(auto itr_city1 = (key_y->second).begin(); itr_city1 != (key_y->second).end(); ++itr_city1){
            min_dist = INF;
            for(auto itr_city2 = (next(key_y)->second).begin(); itr_city2 != (next(key_y)->second).end(); ++itr_city2){
                dist = edge_cost(cites[(*itr_city1) -1], cites[(*itr_city2) -1]);
                if(dist < min_dist){
                    min_dist = dist;
                    city1 = *itr_city1;
                    city2 = *itr_city2;
                }
            }
            edge.set(city1, city2, min_dist);
            edges.push_back(edge);
        }

        for(auto itr_city1 = (key_y->second).begin(); itr_city1 != prev((key_y->second).end()); ++itr_city1){
            city1 = *itr_city1;
            city2 = *next(itr_city1);
            edge.set(city1, city2, edge_cost(cites[city1 -1], cites[city2 -1]));
            edges.push_back(edge);
        }
    }
    Y_to_city_ID.clear();
    dummy.clear();


    sort(edges.begin(), edges.end());

    vertex.resize(N+1);
    for(int i=1; i<=cites.size(); ++i){
        vertex[i] = -1;
    }

    long min_cost = 0;
    for(int i=0; i<edges.size(); ++i){
        if(!same(edges[i].to, edges[i].from)){
            unite(edges[i].to, edges[i].from);
            min_cost += edges[i].cost;\
        }
    }
    cout<<min_cost<<endl;
}
