#include <bits/stdc++.h>
using namespace std; 
int best_dist[100010];
int parents[100010];
int Find(int v){
	if(parents[v] == v)
		return v;
	else{
		parents[v] = Find(parents[v]);
		return parents[v];
	}
}
void Union(int a, int b){
	int fa = Find(a);
	int fb = Find(b);
	if(fa != fb){
		parents[fa] = fb;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector <pair<int,int> > arr_x(n);
	vector <pair<int,int> > arr_y(n);
	for (int i = 0; i < n; ++i)
	{
		int x,y; cin>>x>>y;
		parents[i] = i;
		best_dist[i] = INT_MAX;
		arr_x[i].first = x; arr_x[i].second = i;
		arr_y[i].first = y; arr_y[i].second = i;
	}
	sort(arr_x.begin(), arr_x.end());
	sort(arr_y.begin(), arr_y.end());
	priority_queue <pair<int, pair< int, int > > > pqx;
	priority_queue <pair<int, pair< int, int > > > pqy;
	for (int i = 0; i < n - 1; ++i)
	{
		pqx.push(make_pair(arr_x[i].first - arr_x[i + 1].first, make_pair(arr_x[i].second, arr_x[i+1].second)));
		pqy.push(make_pair(arr_y[i].first - arr_y[i + 1].first, make_pair(arr_y[i].second, arr_y[i+1].second)));
	}
	// int ptrx = 0, ptry = 0;
	long long answer = 0;
	int counter = 0;
	while(counter < n - 1)
	{
		pair<int, pair<int, int> > valx = pqx.top();
		pair<int, pair<int, int> > valy = pqy.top();
		if(-valx.first < -valy.first){
			// cout<<"x chosen "<<valx.second.first<<" "<<valx.second.second<<endl;
			int fa = Find(valx.second.first);
			int fb = Find(valx.second.second);
			if(fa != fb){
				// cout<<"Added\n";
				Union(valx.second.first, valx.second.second);
				answer += -valx.first;
				counter++;
			}
			pqx.pop();			
		}
		else{
			// cout<<"y chosen "<<valy.second.first<<" "<<valy.second.second<<endl;
			int fa = Find(valy.second.first);
			int fb = Find(valy.second.second);
			if(fa != fb){
				// cout<<"Added\n";
				Union(valy.second.first, valy.second.second);
				answer += -valy.first;
				counter++;
			}
			pqy.pop();	
		}
	}
	cout<<answer<<endl;
	return 0;
}