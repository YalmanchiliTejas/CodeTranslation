#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;

    cin >> N;

    multiset <int> m;
   for ( int i = 0; i < N; i ++ ) {
        int a;
        cin >> a;
        
        auto itr = m.lower_bound(a);
        if ( itr == m.begin() ) {
            m.insert( a ); 
        } else {
            itr --;
            m.erase( itr );
            m.insert( a );
        }
    }

//    for ( auto itr = m.begin(); itr != m.end(); itr ++ ) {
//        cout << *itr << endl;
//    }

    cout << m.size() << endl;

    return 0;
}