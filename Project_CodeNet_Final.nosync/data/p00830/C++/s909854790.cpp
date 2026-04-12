#include<iostream>
#include<string>
#include<set>
using namespace std;
#define rep(i, n) for ( int i = 0; i < n; i++ )

set<string> P;
int N, M;

bool exist(string s){
    for ( set<string>::iterator it = P.begin(); it != P.end(); it++ ){
	if ( s.size() <= (*it).size() && s == (*it).substr(0, s.size())) return true;
    }
    return false;
}

bool convert(string str, string &t){
    bool f;
    int p, e;

    if ( str.size() >= 2 && str.substr(str.size()-2, 2) == "/." ){
	str = str.substr(0, str.size()-1);
    }

    for(; (p = str.find("/./")) != string::npos; str.replace(p+1, 2, ""));

    for(; (p = str.find("/..")) != string::npos; ){
	if ( exist(str.substr(0, p+1) ) && p){
	    e = p + 3;
	    p--;
	    while( str[p] != '/') p--;
	    str.replace(p, e-p, "");
	} else return false;
    }
    t = str;
    if ( P.find(t) != P.end()) return true;
    t += (t[t.size()-1]=='/')?"index.html":"/index.html";
    if ( P.find(t) != P.end()) return true;

    return false;
}

main(){
    string path, t1, t2;
    while( cin >> N >> M && (N || M) ){
	P.clear();
	rep(i, N) { cin >> path; P.insert(path); }
	rep(i, M){
	    cin >> t1 >> t2;
	    string c1, c2;
	    if ( convert(t1, c1) && convert(t2, c2) ){
		if ( c1 == c2 ) cout << "yes" << endl;
		else cout << "no" << endl;
	    } else {
		cout << "not found" << endl;
	    }
	}
    }
}