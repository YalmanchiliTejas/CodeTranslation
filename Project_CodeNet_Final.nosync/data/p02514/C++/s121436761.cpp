#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
using namespace std;

class Link {
public:
	int x1;
	int x2;
	int y1;
	int y2;
	string to;
};

class Page {
public:
	int nl;
	vector<Link> lk;
};

int main() {
	int n;
	while (cin >> n, n) {
		int W, H;
		cin >> W >> H;
		vector<Page> pg;
		vector<string> dic(n, "");
		map<string, int> rdic;
		for (int i=0; i<n; i++) {
			Page t;
			cin >> dic[i] >> t.nl;
			for (int j=0; j<t.nl; j++) {
				Link tl;
				cin >> tl.x1 >> tl.y1 >> tl.x2 >> tl.y2 >> tl.to;
				t.lk.push_back(tl);
			}
			rdic[dic[i]] = i;
			pg.push_back(t);
		}

		list<int> buf(1, 0);
		list<int>::iterator p = buf.begin();
		int N;
		cin >> N;
		for (int i=0; i<N; i++) {
			string cmd;
			cin >> cmd;
			if (cmd == "click") {
				int x, y;
				cin >> x >> y;
				for (int i=0; i<pg[*p].nl; i++) {
					if (pg[*p].lk[i].x1<=x && pg[*p].lk[i].x2>=x && pg[*p].lk[i].y1<=y && pg[*p].lk[i].y2>=y) {
						if (p != --buf.end()) p = --(buf.erase(++p, buf.end()));
						buf.push_back(rdic[pg[*p].lk[i].to]);
						p++;
						break;
					}
				}
			} else if (cmd == "back") {
				if (p!=buf.begin()) p--;
			} else if (cmd == "forward") {
				if (p!=--buf.end()) p++;
			} else if (cmd == "show") {
				cout << dic[*p] << endl;				
			}
		}
	}
	return 0;
}