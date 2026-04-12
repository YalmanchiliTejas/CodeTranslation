#include <bits/stdc++.h>
using namespace std;

int n, cnt;
long long ans;

struct data
{
    int x, y, id;
} town[100005];

bool cmp1(data f, data s) {return f.x < s.x;}
bool cmp2(data f, data s) {return f.y < s.y;}

class Disjoint_Set
{
    struct data {
        int parent;
        int rankk;
    } Node[300005];

public:
    void MakeSet(int x)
    {
        Node[x].parent = x;
        Node[x].rankk = 0;
    }

    int FindSet(int x)
    {
        if(Node[x].parent == x)
            return x;
        else
            Node[x].parent = FindSet(Node[x].parent);

        return Node[x].parent;
    }

    void UnionSet(int x, int y)
    {
        int i = FindSet(x);
        int j = FindSet(y);

        if(i == j)
            return ;

        if(Node[i].rankk == Node[j].rankk) { //If they have the same depth
            Node[i].rankk++;
            Node[j].parent = i;
        } else if (Node[i].rankk > Node[j].rankk) {
            Node[j].parent = i;
        } else {
            Node[i].parent = j;
        }
    }
};

Disjoint_Set DS;

struct data2
{
    int node1;
    int node2;
    int weight;
} Edges[300005];

bool Sorter(data2 x, data2 y)
{
    return x.weight < y.weight;
}

void Kruskal()
{
    sort(Edges, Edges+cnt, Sorter);
    for(int i=0; i<cnt; i++) {
        int root1 = DS.FindSet(Edges[i].node1); //find representative of node1
        int root2 = DS.FindSet(Edges[i].node2); //find representative of node2

        if(root1 != root2) {
            DS.UnionSet(Edges[i].node1, Edges[i].node2);
            ans += Edges[i].weight; //total length of MST
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> town[i].x >> town[i].y;
        town[i].id = i;
    }

    sort(town+1, town+n+1, cmp1);
    for(int i=1; i<=n-1; i++) {
        Edges[cnt].node1 = town[i].id;
        Edges[cnt].node2 = town[i+1].id;
        Edges[cnt].weight = abs(town[i+1].x-town[i].x);
        DS.MakeSet(town[i].id);
        DS.MakeSet(town[i+1].id);
        cnt++;
    }
    sort(town+1, town+n+1, cmp2);
    for(int i=1; i<=n-1; i++) {
        Edges[cnt].node1 = town[i].id;
        Edges[cnt].node2 = town[i+1].id;
        Edges[cnt].weight = abs(town[i+1].y-town[i].y);
        DS.MakeSet(town[i].id);
        DS.MakeSet(town[i+1].id);
        cnt++;
    }
    Kruskal();

    return 0;
}