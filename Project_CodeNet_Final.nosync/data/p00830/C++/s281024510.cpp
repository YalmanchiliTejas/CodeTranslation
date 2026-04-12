#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

typedef pair<string, bool> psb;

#define MAX_N 10000

int cnt;
vector <int> graph[MAX_N];
vector <map<pair<string, bool>, int> > val;

void rec(int i, string s) {
  string t = "";
  int p;
  for (p = 0; p < s.size() && s[p] != '/'; p++) t += s[p];


  if (p >= s.size()) {		// ????????????
    map<psb, int>::iterator it = val[i].find(make_pair(t, false));
    if (it == val[i].end()) {
      val[i][make_pair(t, false)] = cnt;
      graph[i].push_back(cnt);
      graph[cnt].push_back(i);
      // cout << i << "-" << cnt << ":" << t << ";f" << endl;
      cnt++;
    }
  }else {			// ?????£??¬?????????
    string ns = s.substr(p+1);

    map<psb, int>::iterator it = val[i].find(make_pair(t, true));
    if (it == val[i].end()) {
      val[i][make_pair(t, true)] = cnt;
      // cout << i << "-" << cnt << ":" << t << ";d" << endl;
      cnt++;
      rec(cnt-1, ns);
    }else {
      rec((*it).second, ns);
    }
  }
  // cout << endl;
}

int check(string s) {
  // cout << s << endl;

  stack <int> st;
  st.push(0);
  while (!st.empty()) {
    int p = st.top();

    string t = "";;
    int i;
    for (i = 0; i < s.size() && s[i] != '/'; i++) t += s[i];
    // cout << t << endl;
    if (t == ".") {
      if ((i+1 == s.size() && s[i] == '/') || i == s.size()) {
	map<psb, int>::iterator it = val[p].find(psb("index.html", false));
	if (it != val[p].end()) {
	  return (*it).second;;
	}else {
	  return -1;
	}
      }
      s = s.substr(i+1);
      continue;
    }
    if (t == "..") {
      if (st.size() > 1) st.pop();
      p = st.top();
      // cout << p << endl;
      // for (map<psb, int>::iterator it2 = val[p].begin(); it2 != val[p].end(); it2++) {
      // 	cout << (*it2).first.first << " ";
      // }
      // puts("");
      // cout << s << " " << i << " " << s.size() << endl;
      if ((i+1 == s.size() && s[i] == '/') || i == s.size()) {
	map<psb, int>::iterator it = val[p].find(psb("index.html", false));
	if (it != val[p].end()) {
	  return (*it).second;;
	}else {
	  return -1;
	}
      }     
      s = s.substr(i+1);
      continue;
    }
    if (i >= s.size() || (i+1 == s.size() && s[i] == '/')) {
      map<psb, int>::iterator it = val[p].find(psb(t, true)); // ?????£??¬?????????
      if (it != val[p].end()) {				       // ????????°??????
	int np = (*it).second;

	it = val[np].find(psb("index.html", false));
	if (it != val[np].end()) {
	  // psb temp = (*it).first;
	  // cout << (*it).first.first << " " << endl;
	  return (*it).second;
	}
	// for (map<psb, int>::iterator it = val[np].begin(); it != val[np].end(); it++) {
	//   if ((*it).first.second) continue;

	//   if ((*it).first.first == t) {
	//     return (*it).second;
	//   }
	// }
      }
      if (i+1 != s.size()) {	// "/"??§???????????????????????????????????¨????????????????????????
	it = val[p].find(psb(t, false));
	if (it != val[p].end()) {
	  return (*it).second;
	}
	if (t == "") {
	  it = val[p].find(psb("index.html", false));
	  if (it != val[p].end()) {
	    return (*it).second;
	  }
	}
      }
      return -1;
    }else {			// ?????£??¬??????????????¨???
      map<psb, int>::iterator it = val[p].find(psb(t, true));
      if (it != val[p].end()) {
	st.push((*it).second);
	s = s.substr(i+1);
      }else {
	return -1;
      }
    }
  }
}


int main() {
  int n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    // vector <int> graph[MAX_N];
    // vector <map<pair<string, bool>, int> > val;

    vector <int> emptyvec;
    for (int i = 0; i < MAX_N; i++) graph[i] = emptyvec;
    vector <map<psb, int> > emptyval;
    val = emptyval;

    for (int i = 0; i < MAX_N; i++) {
      map<psb, int> nmap;
      val.push_back(nmap);
    }
    cnt++;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      rec(0, s.substr(1));
    }
    for (int i = 0; i < m; i++) {
      string q1, q2;
      cin >> q1 >> q2;
      int a1 = check(q1.substr(1)), a2 = check(q2.substr(1));
      // cout << a1 << " " << a2 << endl;
      if (a1 != -1 && a1 == a2) {
	puts("yes");
      }else if (a1 == -1 || a2 == -1) {
	puts("not found");
      }else {
	puts("no");
      }
    }
  }
}