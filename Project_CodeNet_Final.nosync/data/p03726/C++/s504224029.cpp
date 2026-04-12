#include <bits/stdc++.h>
using namespace std;

#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define REP2(i,n) for(int i=0;i<(int)(n);i++)
#define REP3(i,m,n) for(int i=m;i<(int)(n);i++)
#define REP4(i,m,n,s) for(int i=m;(s>0 and i<(int)(n)) or (s<0 and i>(int)(n));i+=s)
#define REP(...) GET_MACRO(__VA_ARGS__, REP4, REP3, REP2)(__VA_ARGS__)
#define REPIT(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define PIS(x) printf("%d ",x)
#define PRINTIA(a,n) REP(i,n){printf("%d ", *((a)+i));}putchar('\n');
#define PN() putchar('\n')
#define MP make_pair
#define PB push_back

typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

void RI() {}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
void PI() {putchar('\n');}
template<typename... T>
void PI(const int head, T... tail ) {
    printf("%d ", head);
    PI(tail...);
}

#define MAX_N 100005

unordered_set<int> G[MAX_N];
unordered_set<int> leaf;

void delete_node(int v) {
    REPIT(ii, G[v]) {
        G[*ii].erase(v);
    }
    leaf.erase(v);
}

int main()
{
    int N;
    RI(N);
    REP(i, N-1) {
        int a, b;
        RI(a, b);
        G[a].insert(b);
        G[b].insert(a);
    }
    //PN();

    REP(i, 1, N+1) {
        if(G[i].size() == 1) {
            leaf.insert(i);
        }
    }

    while(!leaf.empty()) {
        int v = *(leaf.cbegin());
        leaf.erase(v);

        if(G[v].size() == 0) {
            //PI(11111, v);
            printf("First\n");
            return 0;
        }
        int p = *(G[v].cbegin());
        delete_node(v);

        //PI(p, v);

        REPIT(ii, G[p]) {
            if(leaf.find(*ii) != leaf.end()) {
                //PI(22222, p, v, *ii);
                printf("First\n");
                return 0;
            }
        }
        REPIT(ii, G[p]) {
            if(G[*ii].size() == 2) {
                leaf.insert(*ii);
            }
        }
        delete_node(p);
    }
    printf("Second\n");
    return 0;
}
