#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

typedef vector <string> VS;
typedef pair <string, string> PSS;
typedef vector <PSS> VPSS;
typedef VS PATH;
typedef VS FILES;
typedef PSS QUERY;
typedef vector <QUERY> QUERIES;
typedef set <PATH> PATHS;

const string NOT_FOUND = "not found";
const string YES = "yes";
const string NO = "no";
const string INDEX_HTML = "index.html";

PATHS D;
PATHS I;
PATHS F;

void init();
void print_vs( VS );
VS to_path( string );
VS to_strictpath( string );
void register_dir( PATH );
bool exist_dir( PATH );
void register_directory_index( PATH );
bool exist_indexhtml( PATH );
void register_file( string );
bool exist_file( PATH );

void init() {
    D.clear();
    I.clear();
    F.clear();
}

void print_vs( VS vs ) {
    for ( VS ::iterator it_i = vs.begin(); it_i != vs.end(); ++ it_i ) {
        cout << *it_i;
        if ( it_i + 1 != vs.end() ) {
            cout << " ";
        }
    }
    cout << endl;
}

VS to_path( string s_path ) {
    replace( s_path.begin(), s_path.end(), '/', ' ' );
    VS path;
    istringstream is( s_path );
    string dir;
    while ( is >> dir ) {
        path.push_back( dir );
    }
    return path;
}

VS to_strictpath( string s_path ) {
    VS path = to_path( s_path );
    VS strictpath;
    for ( VS ::iterator it_i = path.begin(); ! path.empty() && it_i + 1 != path.end(); ++ it_i ) {
        if ( *it_i == ".." ) {
            strictpath.pop_back();
        } else if ( *it_i != "." ) {
            strictpath.push_back( *it_i );
        }
    }
    if ( path.empty() ) {
        PATH root;
        if ( exist_indexhtml( root ) ) root.push_back( INDEX_HTML );
    } else {
        string lastone = *( path.end() - 1 );
        if ( lastone == ".." ) {
            strictpath.pop_back();
        } else if ( lastone != "." ) {
            strictpath.push_back( lastone );
        }
        if ( ! exist_file( strictpath ) && exist_indexhtml( strictpath ) ) strictpath.push_back( INDEX_HTML );
    }
    return strictpath;
}

void register_dir( PATH path ) {
    D.insert( path );
}

bool exist_dir( PATH path ) {
    return D.find( path ) != D.end();
}

void register_directory_index( PATH path ) {
    I.insert( path );
}

bool exist_indexhtml( PATH path ) {
    return I.find( path ) != I.end();
}

void register_file( string filepath ) {
    PATH path = to_path( filepath );
    F.insert( path );
}

bool exist_file( PATH path ) {
    return F.find( path ) != F.end();
}

void register_subdir( string filepath ) {
    PATH path = to_path( filepath );
    PATH sub;
    for ( PATH ::iterator it_i = path.begin(); ! path.empty() && it_i + 1 != path.end(); ++ it_i ) {
        sub.push_back( *it_i );
        register_dir( sub );
    }
    if ( *( path.end() - 1 ) == INDEX_HTML ) {
        register_directory_index( sub );
    }
}

void register_files( FILES files ) {
    PATH root;
    register_dir( root );
    for ( FILES ::iterator it_i = files.begin(); it_i != files.end(); ++ it_i ) {
        register_subdir( *it_i );
        register_file( *it_i );
    }
}

bool valid_path( string filepath ) {
    PATH path = to_path( filepath );
    int depth = 0;
    for ( PATH ::iterator it_i = path.begin(); it_i != path.end(); ++ it_i ) {
        if ( *it_i == ".." ) {
            depth -= 1;
        } else if ( *it_i != "." ) {
            depth += 1;
        }
    }
    if ( depth < 0 ) return false;

    PATH sub;
    bool flag = false;
    for ( PATH ::iterator it_i = path.begin(); ! path.empty() && it_i + 1 != path.end(); ++ it_i ) {
        if ( *it_i == ".." ) {
            sub.pop_back();
        } else if ( *it_i != "." ) {
            sub.push_back( *it_i );
        }
        if ( ! exist_dir( sub ) ) {
            flag = true;
        }
    }
    if ( flag ) return false;
    
    if ( path.empty() ) {
        PATH root;
        if ( ! exist_indexhtml( root ) ) return false;
    } else {
        string lastone = *( path.end() - 1 );
        if ( lastone == ".." ) {
            sub.pop_back();
        } else if ( lastone != "." ) {
            sub.push_back( lastone );
        }
        if ( ! exist_file( sub ) && ! exist_indexhtml( sub ) ) return false;
    }
    return true;
}

bool is_directory_path( string path ) {
    return path[path.size()-1] == '/';
}

string check_same( QUERY query ) {
    string filepath1 = query.first;
    string filepath2 = query.second;
    if ( !valid_path( filepath1 ) || !valid_path( filepath2 ) ) return NOT_FOUND;
    if ( is_directory_path( filepath1 ) ) filepath1 += INDEX_HTML;
    if ( is_directory_path( filepath2 ) ) filepath2 += INDEX_HTML;
    if ( !valid_path( filepath1 ) || !valid_path( filepath2 ) ) return NOT_FOUND;
    PATH path1 = to_strictpath( filepath1 );
    PATH path2 = to_strictpath( filepath2 );
    return path1 == path2 ? YES : NO;
}

void solve( QUERIES queries ) {
    for ( QUERIES ::iterator it_i = queries.begin(); it_i != queries.end(); ++ it_i ) {
        cout << check_same( *it_i ) << endl;
    }
}

int main() {
    int n, m;
    while ( cin >> n >> m ) {
        if ( n == 0 && m == 0 ) {
            break;
        }
        FILES files( n );
        for ( int i = 0; i < n; ++ i ) {
            cin >> files[i];
        }
        register_files( files );
        QUERIES queries( m );
        for ( int i = 0; i < m; ++ i ) {
            cin >> queries[i].first;
            cin >> queries[i].second;
        }
        solve( queries );
        init();
    }
    return 0;
}