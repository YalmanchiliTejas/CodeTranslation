#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<typeinfo>
#include<functional>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;



struct tree{

    struct node{
        ll a;
        ll p;
        node* l;
        node* r;
    };
    
    node NIL={-1,-1,NULL,NULL};
    node* root=&NIL;
    
    tree(){
        NIL.r=NIL.l=&NIL;
    }

    /*
     rightRotate(Node t)
     Node s = t.left
     t.left = s.right
     s.right = t
     return s // root of the subtree
     leftRotate(Node t)
     Node s = t.right
     t.right = s.left
     s.left = t
     return s // root of the subtree
     */
    
    
    node & Rrotate(node &t){
        node &s=*t.l;
        t.l=s.r;
        s.r=&t;
        return s;
    }

    node & Lrotate(node &t){
        node &s=*t.r;
        t.r=s.l;
        s.l=&t;
        return s;
    }

    /*
     insert(Node t, int key, int priority)            // 再帰的に探索
     if t == NIL
     return Node(key, priority)               // 葉に到達したら新しい節点を生成して返す
     if key == t.key
     return t                                 // 重複したkeyは無視
     
     if key < t.key                               // 左の子へ移動
     t.left = insert(t.left, key, priority)   // 左の子へのポインタを更新
     if t.priority < t.left.priority          // 左の子の方が優先度が高い場合右回転
     t = rightRotate(t)
     else                                         // 右の子へ移動
     t.right = insert(t.right, key, priority) // 右の子へのポインタを更新
     if t.priority < t.right.priority         // 右の子の方が優先度が高い場合左回転
     t = leftRotate(t)
     
     return t
     */
    
    node & insert(ll k,ll p){
        if(root==&NIL){
            root=(node*)malloc(sizeof(node));
            root->p=p;
            root->a=k;
            root->r=root->l=&NIL;
            return *root;
        }
        return *(root=&insert(*root,k,p));
    }

    node & insert(node &t,ll k,ll p){
        if(&t==&NIL){
            node &a=*(node*)malloc(sizeof(node));
            a.a=k;
            a.p=p;
            a.r=a.l=&NIL;
            return a;
        }
        if(k==t.a){return t;}
        if(k<t.a){
            t.l=&insert(*t.l,k,p);
            if(t.p<t.l->p){
                return Rrotate(t);
            }
        }
        else{
            t.r=&insert(*t.r,k,p);
            if(t.p<t.r->p){
                return Lrotate(t);
            }
        }
        return t;
    }

    /*
     delete(Node t, int key)
     if t == NIL
     return NIL
     if key < t.key                                // 削除対象を検索
     t.left = delete(t.left, key)
     else if key > t.key
     
     
     t.right = delete(t.right, key)
     else
     return _delete(t, key)
     return t
     
     _delete(Node t, key) // 削除対象の節点の場合
     if t.left == NIL && t.right == NIL           // 葉の場合
     return NIL
     else if t.left == NIL                        // 右の子のみを持つ場合左回転
     t = leftRotate(t)
     else if t.right == NIL                       // 左の子のみを持つ場合右回転
     t = rightRotate(t)
     else                                         // 左の子と右の子を両方持つ場合
     if t.left.priority > t.right.priority    // 優先度が高い方を持ち上げる
     t = rightRotate(t)
     else
     t = leftRotate(t)
     return delete(t, key)
     */

    node & _delete(node &t,ll k){
        if(t.l==&NIL && t.r==&NIL){return NIL;}
        else if(t.l==&NIL){
            return erase(Lrotate(t),k);
        }
        else if(t.l==&NIL){return erase(Rrotate(t),k);}
        else if(t.r==&NIL){return erase(Rrotate(t),k);}
        else{
            if(t.l->p>t.r->p){
                return erase(Rrotate(t),k);
            }
            else{
                return erase(Lrotate(t),k);
            }
        }
        return t;
    }

    node & erase(node &t,ll k){
        if(&t==&NIL){
            return NIL;
        }
        if(k<t.a){t.l=&erase(*t.l,k);}
        else if(k>t.a){
            t.r=&erase(*t.r,k);
        }
        else{
            return _delete(t,k);
        }
        return t;
    }

    node & erase(ll k){
        if(root==&NIL){return NIL;}
        return *(root=&erase(*root,k));
    }
    
    void test(){
        dfs_m(*root);
        cout<<endl;
        dfs_f(*root);
        cout<<endl;
    }
    
    void dfs_f(node &w){
        cout<<" "<<w.a;
        if(w.l!=&NIL){dfs_f(*w.l);}
        if(w.r!=&NIL){dfs_f(*w.r);}
    }
    
    void dfs_m(node &w){
        if(w.l!=&NIL){dfs_m(*w.l);}
        cout<<" "<<w.a;
        if(w.r!=&NIL){dfs_m(*w.r);}
    }
    
    bool find(ll a){
        if(root==&NIL){return false;}
        node* w=root;
        while(1){
            if(w->a==a){return true;}
            if(w->a<a && w->r==&NIL){return false;}
            if(w->a<a){w=w->r;}
            if(w->a>a && w->l==&NIL){return false;}
            if(w->a>a){w=w->l;}
        }
        return false;
    }
};



int main(){
    tree B;
    ll q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(s=="insert"){
            ll b,p;
            cin>>b>>p;
            B.insert(b,p);
        }
        else if(s=="find"){
            ll b;
            cin>>b;
            if(B.find(b)){cout<<"yes"<<endl;}
            else{cout<<"no"<<endl;}
        }
        else if(s=="print"){
            B.test();
        }
        else{
            ll b;
            cin>>b;
            B.erase(b);
        }
    }
    
    
    return 0;
}

