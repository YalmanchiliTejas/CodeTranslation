#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "yes" << endl;}
void no(){ cout << "no" << endl;}

//-----------------------------------------
template<class T>
class Treap{
  private:
    struct Node{
      T key; 
      int pri;
      Node *lef, *rig;
    };
    Node *NIL, *root;
  public:
    Treap(){
      NIL = NULL;
      root = NULL;
    }

    Node *create(T key, int pri, Node* l, Node* r){
      Node *newn = (Node *)malloc(sizeof(Node));
      newn->key = key;
      newn->pri = pri;
      newn->lef = l;
      newn->rig = r;
      return newn;
    }

    Node *right_rotate(Node *t){
      Node *s = t->lef;
      t->lef = s->rig;
      s->rig = t;
      return s;
    }

    Node *left_rotate(Node *t){
      Node *s = t->rig;
      t->rig = s->lef;
      s->lef = t;
      return s;
    }

    Node *insert_node(Node *t, T key, int pri){
      if(t == NIL) return create(key, pri, NIL, NIL);
      if(key == t->key) return t;

      if(key < t->key){
        t->lef = insert_node(t->lef, key, pri);
        if(t->pri < t->lef->pri){
          t = right_rotate(t);
        }
      }
      else{
        t->rig = insert_node(t->rig, key, pri);
        if(t->pri < t->rig->pri){
          t = left_rotate(t);
        }
      }
      return t;
    }

    void insert(T key, int pri){
      root = insert_node(root, key, pri);
    }

    Node *find_node(Node *t, T k){
      if(t == NIL) return NIL;
      if(t->key == k) return t;
      if(k < t->key) return find_node(t->lef,k);
      else return find_node(t->rig,k);
    }

    bool find(T k){
      Node *t = find_node(root,k);
      if(t == NIL) return false;
      else return true;
    }

    Node *remove_node(Node *t, T key){
      if(t == NIL) return NIL;
      if(key < t->key){
        t->lef = remove_node(t->lef,key);
      }
      else if(key > t->key){
        t->rig = remove_node(t->rig,key);
      }
      else{
        return remove_rot(t,key);
      }
      return t;
    }

    Node *remove_rot(Node *t, T key){
      if(t->lef == NIL && t->rig == NIL){
        return NIL;
      }
      else if(t->lef == NIL){
        t = left_rotate(t);
      }
      else if(t->rig == NIL){
        t = right_rotate(t);
      }
      else{
        if(t->lef->pri < t->rig->pri){
          t = left_rotate(t);
        }
        else{
          t = right_rotate(t);
        }
      }
      return remove_node(t,key);
    }

    void remove(T key){
      root = remove_node(root,key);
    }


    void pmid(Node *t){
      if(t == NIL) return;
      pmid(t->lef);
      cout << " " << t->key;
      pmid(t->rig);
    }

    void ppre(Node *t){
      if(t == NIL) return;
      cout << " " << t->key;
      ppre(t->lef);
      ppre(t->rig);
    }

    void pr(){
      pmid(root);
      cout <<endl;
      ppre(root);
      cout <<endl;
    }
};
//-----------------------------------------

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  Treap<int> tree;
  REP(i,n){
    string s;
    cin >> s;
    if(s[0] == 'i'){
      int a, b;
      cin >> a >> b;
      tree.insert(a,b);
    }
    else if(s[0] == 'f'){
      int a;
      cin >> a;
      if(tree.find(a)) yes();
      else no();
    }
    else if(s[0] == 'd'){
      int a;
      cin >> a;
      tree.remove(a);
    }
    else{
      tree.pr();
    }
  }



  return 0;
}




