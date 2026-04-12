#include <bits/stdc++.h>

inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

using namespace std;

const int maxn = 2e5 + 50;

int ans[maxn] , anslen;

namespace Splay{
	int ch[maxn][2] , s[maxn] , root , fa[maxn];
	int lzy[maxn];
	stack < int > allocate , stk;
	int key[maxn];

	void Add( int x ){
		lzy[x] ^= 1;
	}

	inline void up(int x){
		s[x] = s[ch[x][0]] + s[ch[x][1]] + 1;
    }

    void ReleaseLabel( int x ){
        if( !lzy[x] )
            return;
    	if( ch[x][0] )
    		Add( ch[x][0] );
    	if( ch[x][1] )
    		Add( ch[x][1] );
    	lzy[x] = 0;
    	swap( ch[x][0] , ch[x][1] );
    }

    void rotate( int x, int d ){
        int y = fa[x];
        ch[y][d ^ 1] = ch[x][d];
        if ( ch[x][d] ) fa[ch[x][d]] = y;  
        fa[x] = fa[y];
        if (fa[y]){
            if (y == ch[fa[y]][d])  ch[fa[y]][d] = x;
            else  ch[fa[y]][d ^ 1] = x;
        }
        ch[x][d] = y , fa[y] = x;
        up( y ) , up( x );
    }

    void Splay( int x , int target ){
        int y = x;
        while( y ^ target )
            stk.push( y ),
            y = fa[y];
        while( !stk.empty() )
            ReleaseLabel( stk.top() ),
            stk.pop();
    	while( fa[x] != target ){
    		int y = fa[x];
    		if( x == ch[y][0] ){
    			if( fa[y] != target && y == ch[fa[y]][0])
    				rotate( y , 1 );
    			rotate( x , 1 );
    		}else{
    			if( fa[y] != target && y == ch[fa[y]][1])
    				rotate( y , 0 );
    			rotate( x , 0 );
    		}
    	}
    	if( !target ) root = x;
    }

    void Insert( int & x , int val , int par = 0 ){
    	if( x == 0 ){
    		x = allocate.top(); allocate.pop();
    		ch[x][0] = ch[x][1] = 0 , s[x] = 1 , key[x] = val , lzy[x] = 0 , fa[x] = par;
    		Splay( x , 0 );
    	}else{
    		int cur = x;
    		ReleaseLabel( cur );
    		Insert( ch[x][1] , val , x );
    	}
    }

    void dfs( int u ){
    	if(!u) return;
    	ReleaseLabel( u );
    	dfs( ch[u][0] );
    	ans[anslen++] = key[u];
    	dfs( ch[u][1] );
    }

};

int n ;

int main(int argc,char *argv[]){
	n = read();
	for(int i = 1 ; i <= n ; ++ i)
		Splay::allocate.push( i );
	for(int i = 1 ; i <= n ; ++ i){
		int x = read();
		Splay::Insert( Splay::root , x );
		Splay::Add( Splay::root );
	}
	Splay::dfs( Splay::root );
	for(int i = 0 ; i < anslen ; ++ i)
		printf( "%d " , ans[i] );
	puts( "" );
	return 0;
}