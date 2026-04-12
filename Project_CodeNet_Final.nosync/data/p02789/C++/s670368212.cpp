#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using INT = long long int;
const INT INF = INT(1) << 60;

#define FOR(i, N) for( INT i = 0; i < N; i++ )
#define FOR2(i, j, N) for ( INT i = 0; i < N; i++ ) FOR(j, N)
#define FOR3(i, j, k, N) for ( INT i = 0; i < N; i++ ) FOR2(j, k, N)

#define FORR(i, N) for( INT i = (N-1); i >= 0; i-- )
#define FORR2(i, j, N) for( INT i = (N-1); i >= 0; i-- ) FORR(j, N)
#define FORR3(i, j, k, N) for( INT i = (N-1); i >= 0; i-- ) FORR2(j, k, N)

#define Comb_Idx2(i, j, N) for( INT i = 0; i < N; i++ ) for( INT j = i; j < N; j++ )
#define Comb_Idx3(i,j,k, N) Comb_Idx2(i,j,N) for( INT k = j; k < N; k++ )
#define Comb_Idx4(i,j,k,l, N)  Comb_Idx3(i,j,k,N) for( INT l = k; l < N; l++ )

#define RANGE(v) begin(v), end(v)

#define VECTOR(TYPE, N, INIT_VALUE) std::vector<TYPE>(N, INIT_VALUE)
#define VECTOR2(TYPE, N, M, INIT_VALUE) std::vector< std::vector< TYPE > >( (N), std::vector<TYPE>(M, INIT_VALUE) )
#define VECTOR3(TYPE, N, M, L, INIT_VALUE) std::vector< std::vector< std::vector< TYPE > > >( (N), VECTOR2(TYPE, M, L, INIT_VALUE) )
#define VECTOR4(TYPE, N, M, L, K, INIT_VALUE) std::vector< std::vector< std::vector< std::vector< TYPE > > > > ( (N), VECTOR3(TYPE, M, L, K, INIT_VALUE) )

template< class T >
T chmax( T& lhs, const T& rhs){
    lhs = std::max( lhs, rhs);
    return lhs;
}
template< class T >
T chmin( T& lhs, const T& rhs){
    lhs = std::min( lhs, rhs);
    return lhs;
}

template< class T >
std::istream& operator>> ( std::istream& lhs, std::vector<T>& rhs){
    for( auto& elem: rhs ){
        lhs >> elem;
    }
    return lhs;
}

template< class T, class F >
bool ANY( std::initializer_list<T> sequence, F func ){
    for(  auto&& t : sequence ){
        if( func(t) ){ return true; }
    }
    return false;
}
template< class T, class F >
bool ALL( std::initializer_list<T> sequence, F func ){
    for(  auto&& t : sequence ){
        if( ! func(t) ){ return false; }
    }
    return true;
}
template< class T, class F >
bool ANY( T sequence, F func ){
    for(  auto&& t : sequence ){
        if( func(t) ){ return true; }
    }
    return false;
}
template< class T, class F >
bool ALL( T sequence, F func ){
    for(  auto&& t : sequence ){
        if( ! func(t) ){ return false; }
    }
    return true;
}

template< class T >
T safe_get ( const std::vector<T>& v, INT idx, T def = -1 ){
    if( idx < 0 || v.size() <= idx ){
        return def;
    } else {
        return v[idx];
    }
}
template< class T >
T safe_get ( const std::vector< std::vector<T> >& vv, INT idx1, INT idx2, T def = -1 ){
    if( idx1 < 0 || vv.size() <= idx1 ){
        return def;
    } else {
        return safe_get(vv[idx1], idx2, def );
    }
}

// ======================== DEBUG ======================== //

const int __SETW__ = 5;

template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::priority_queue<T>& rhs ){
    std::queue<T> copy = rhs;
    while( !copy.empty() ){
        lhs << std::setw(__SETW__) << copy.front() << " ";
        copy.pop();
    }
    return lhs;
}
template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::queue<T>& rhs ){
    std::queue<T> copy = rhs;
    while( !copy.empty() ){
        lhs << std::setw(__SETW__) << copy.front() << " ";
        copy.pop();
    }
    return lhs;
}
template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::stack<T>& rhs ){
    std::stack<T> copy = rhs;
    while( !copy.empty() ){
        lhs << std::setw(__SETW__) << copy.top() << " ";
        copy.pop();
    }
    return lhs;
}

template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::vector< std::vector<T> >& rhs ){
    for( auto&& v : rhs ){
        lhs << v << endl;
    }
    return lhs;
}
template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::vector<T>& rhs ){
    for( auto&& t : rhs ){
        lhs << std::setw(__SETW__) << t << " ";
    }
    return lhs;
}
template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::list<T>& rhs ){
    for( auto&& t : rhs ){
        lhs << std::setw(__SETW__) << t << " ";
    }
    return lhs;
}

template< class T1, class T2 >
std::ostream& operator<< ( std::ostream& lhs, const std::map<T1, T2>& rhs ){
    for( auto&& m : rhs ){
        lhs << std::setw(__SETW__) << m.first << ":" << std::setw(__SETW__) << m.second << endl;
    }
    return lhs;
}
template< class T1, class T2 >
std::ostream& operator<< ( std::ostream& lhs, const std::multimap<T1, T2>& rhs ){
    for( auto&& m : rhs ){
        lhs << std::setw(__SETW__) << m.first << ":" << std::setw(__SETW__) << m.second << endl;
    }
    return lhs;
}
template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::set<T>& rhs ){
    for( auto&& t : rhs ){
        lhs << std::setw(__SETW__) << t << " ";
    }
    return lhs;
}
template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::multiset<T>& rhs ){
    for( auto&& t : rhs ){
        lhs << std::setw(__SETW__) << t << " ";
    }
    return lhs;
}

template< class T >
std::ostream& operator<< ( std::ostream& lhs, const std::complex<T>& rhs ){
    std::streamsize ss = lhs.precision();
    lhs << "(" << std::setw(5) << std::setprecision(4) << rhs.real() << ","
               << std::setw(5) << std::setprecision(4) << rhs.imag() << ") ";
    lhs.precision(ss);
    return lhs;
}
template< class T1, class T2 >
std::ostream& operator<< ( std::ostream& lhs, const std::pair<T1, T2>& rhs ){
    lhs << "(" << rhs.first << "," << rhs.second << ")";
    return lhs;
}

// ======================== DEBUG ======================== //

// ======================== STAGIGN ======================== // 

#define FORO(i, N) for( INT i = 1; i <= N; i++ )
#define FORO2(i, j, N) for ( INT i = 1; i <= N; i++ ) FORO(j, N)
#define FORO3(i, j, k, N) for ( INT i = 1; i <= N; i++ ) FORO2(j, k, N)

#define FORRO(i, N) for( INT i = N; i > 0; i-- )
#define FORRO2(i, j, N) for( INT i = N; i > 0; i-- ) FORRO(j, N)
#define FORRO3(i, j, k, N) for( INT i = N; i > 0; i-- ) FORRO2(j, k, N)

#define VFOR(i, VECTOR1D ) for (INT i = 0; i < VECTOR1D.size(); i++ )
#define VFOR2(i, j, VECTOR2D ) for (INT i = 0; i < VECTOR2D.size(); i++ ) VFOR(j, VECTOR2D[i] )
#define VFOR3(i, j, k, VECTOR3D ) for (INT i = 0; i < VECTOR3D.size(); i++ ) VFOR2(j, k, VECTOR3D[i] )

template<class T>
T& SAFE_ACCESSOR(vector<T>& v, INT i){ 
    INT N = v.size();
    assert( -N <= i && i < N );
    i %= N; i = (i<0) ? N+i : i; 
    return v[i]; 
}

#define Viewer(vec) [&vec](INT i) -> auto& { return SAFE_ACCESSOR(vec, i); }
#define Viewer2(vec) [&vec](INT i, INT j) -> auto& { return SAFE_ACCESSOR(SAFE_ACCESSOR(vec, i), j); }
#define Viewer3(vec) [&vec](INT i, INT j, INT k) -> auto& { return SAFE_ACCESSOR(SAFE_ACCESSOR(SAFE_ACCESSOR(vec, i), j), k); }

template< class T > auto ViewAdapter_Transpose(T&& viewer) { return [viewer](INT i, INT j) -> auto& { return viewer(j, i); }; }
template< class T > auto ViewAdapter_Reverse_idx1(T&& viewer, INT N) { return [viewer,N](INT i, INT j) -> auto& { return viewer(N-i-1, j); }; }
template< class T > auto ViewAdapter_Reverse_idx2(T&& viewer, INT N) { return [viewer,N](INT i, INT j) -> auto& { return viewer(i, N-j-1); }; }
template< class T > auto ViewAdapter_Rot90 (T&& viewer, INT N, INT M) { auto nestedView = ViewAdapter_Transpose(viewer); return ViewAdapter_Reverse_idx2(nestedView, N); }
template< class T > auto ViewAdapter_Rot270(T&& viewer, INT N, INT M) { auto nestedView = ViewAdapter_Transpose(viewer); return ViewAdapter_Reverse_idx1(nestedView, M); }
template< class T > auto ViewAdapter_Rot180(T&& viewer, INT N, INT M) { auto nestedView = ViewAdapter_Reverse_idx1(viewer, N); return ViewAdapter_Reverse_idx2(nestedView, M); }

// #define ViewAdapter_Transpose(Viewer) [&Viewer](INT i, INT j) -> auto& { return Viewer(j,i); }
// #define ViewAdapter_Reverse_idx1(Viewer, N) [&Viewer](INT i, INT j) -> auto& { return Viewer(N-i-1, j); }
// #define ViewAdapter_Reverse_idx2(Viewer, N) [&Viewer](INT i, INT j) -> auto& { return Viewer(i, N-j-1); }

// #define ViewAdapter_Rot90(Viewer, N, M) [&Viewer](INT i, INT j) -> auto& { auto nextedViewer = ViewAdapter_Transpose(Viewer); return ViewAdapter_Reverse_idx1(nextedViewer, N); }

// ======================== STAGIGN ======================== // 


using namespace std;

int main(){
    INT N, M;
    cin >> N >> M;

    if( N <= M ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
