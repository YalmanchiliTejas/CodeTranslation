#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
using namespace std;


/*
    |
    Notas:
        - Los valores del subarbol izquierdo de cada nodo son estrictamente menores que
          su valor, y en el subarbol derecho mayores o iguales.

        - split: En L se guardan los nodos con valor estrictamente menor
        que el parametro value
*/

struct node_{
    node_ *l , *r ;
    ll value , priority , tamSubArbol , freq , realTam;
    node_( ll v , ll p ) : value( v ) , priority( p ) , tamSubArbol( 0 ) , freq(1) , realTam(1) , l( nullptr ) , r( nullptr ){}
};

typedef node_ * pnode;

node_ * createNode( ll v = 0 , ll p = 0 ){
    node_ *x = new node_( v , p );
    return x;
}

ll getTam( pnode u ){
    return u ? u->tamSubArbol : 0LL;
}

ll getRealTam( pnode u ){
    return u ? u->realTam : 0LL;
}

void updTam( pnode u ){
    if(!u) return;
    u -> tamSubArbol = getTam( u->l ) + getTam( u->r ) + 1LL;
    u -> realTam = getRealTam( u->l ) + getRealTam( u->r ) + u->freq;
    return;
}

void split( pnode t, ll value , pnode &L , pnode &R ){

    if( !t ){
        L = R = nullptr;
        return;
    }

    if( t->value < value ){
        split( t->r , value , t->r , R );
        L = t;
    }else{
        split( t->l , value , L , t->l );
        R = t;
    }

    updTam( t );

    return;
}

void merge( pnode &t , pnode L , pnode R ){

    if( !L || !R ){
        t = L ? L : R;
        return;
    }

    if( L->priority > R->priority ){
            merge( L->r , L->r , R );
            t = L;
    }else{
            merge( R->l , L , R->l );
            t = R;
    }

    updTam( t );

    return;
}

void insertNode( pnode &t , pnode nd ){

    if( !t ){ t = nd; updTam( t ); return; }

    if( t->priority >= nd->priority ){
        insertNode( t->value >= nd->value ? t->l : t->r , nd );
    }else{
        split( t , nd->value , nd->l , nd->r );
        t = nd;
    }

    updTam( t );

    return;
}

void eraseNode( pnode &t , ll value ){

    if(!t) return;

    if( t->value == value ){
        t->freq--;
        if( !t->freq ) merge( t , t->l , t->r );
    }else{
        eraseNode( t->value >= value ? t->l : t->r , value );
    }

    updTam( t );

    return;
}

bool isInside( pnode currentNode , ll value ){
    if(!currentNode) return false;
    if(currentNode->value==value) return true;
    return currentNode->value>value ? isInside( currentNode->l , value ) : isInside( currentNode->r , value );
}

void add1( pnode currentNode , ll value ){
    if(!currentNode) return;
    if(currentNode->value==value){
        currentNode->freq++;
        updTam( currentNode );
        return;
    }
    if(currentNode->value>value){
            add1( currentNode->l , value );
    }else{
        add1( currentNode->r , value );
    }

    updTam( currentNode );
    return;
}

ll minValue( pnode currentNode ){
    if( !currentNode ) return 0LL;
    if( currentNode->l ) return minValue( currentNode->l );
    return currentNode->value;
}

ll n,a[100010],ans;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution< int > priorities(0, 500000000);

    pnode root = nullptr,L,R;

    cin >> n;
    for(ll i=0; i<n; i++) cin >> a[i];

    for(ll i=n-1; i>=0; i--){
        split( root , a[i]+1 , L , R );
        if( !getTam( R ) ){
                merge( root , L , R );
                if( isInside( root , a[i] ) ){
                    add1( root , a[i] );
                }else{
                    insertNode( root , createNode( a[i] , priorities( rng ) ) );
                }
                ans++;
        }else{
                eraseNode( R , minValue( R ) );
                merge( root , L , R );
                if( isInside( root , a[i] ) ){
                    add1( root , a[i] );
                }else{
                    insertNode( root , createNode( a[i] , priorities( rng ) ) );
                }
        }
    }

    cout << ans;

    return 0;
}

