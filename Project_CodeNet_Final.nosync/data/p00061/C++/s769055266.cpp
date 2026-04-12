#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int, int> pi;
/*
#define num first
#define score second
*/
bool cmp(pi lhs, pi rhs)
{
	return (lhs.second > rhs.second);
}

int main()
{
	int n, a;
	vector <pi> p;
	
	while (scanf("%d,%d", &n, &a), n != 0 || a != 0){
		p.push_back(make_pair(n, a));
	}
	
	sort(p.begin(), p.end(), cmp);
	
	int pt = 31, minnum = 0;
	for (int i = 0; i < p.size(); i++){
		if (pt == p[i].second){
			p[i].second = minnum;
		}
		else {
			pt = p[i].second;
			minnum++;
			p[i].second = minnum;
		}
	}
	
	/*for (int i = 0; i < p.size(); i++){
		cout << p[i].first << " " << p[i].second << endl;
	}*/
	
	int team;
	while (scanf("%d", &team) != EOF){
		for (int i = 0; i < p.size(); i++){
			if (team == p[i].first){
				cout << p[i].second << endl;
			}
		}
	}
	
	return (0);
}