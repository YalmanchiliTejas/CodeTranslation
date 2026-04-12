#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int x[N];
int y[N];
int arr[N];
vector < pair < int , pair < int , int > > > v;
int parent[N];
long long ans;
int cost(int a , int b){
	return min(abs(x[a] - x[b]) , abs(y[a] - y[b]));
}
int find(int node){
	if(parent[node] == node){
		return node;
	}
	return parent[node] = find(parent[node]);
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , x + i , y + i);
		arr[i] = i;
		parent[i] = i;
	}
	sort(arr + 1 , arr + 1 + n , [](int a , int b){
		return x[a] < x[b];
	});
	for(int i = 1 ; i < n ; ++i){
		v.push_back({cost(arr[i] , arr[i + 1]) , {arr[i] , arr[i + 1]}});
	}
	sort(arr + 1 , arr + 1 + n , [](int a , int b){
		return y[a] < y[b];
	});
	for(int i = 1 ; i < n ; ++i){
		v.push_back({cost(arr[i] , arr[i + 1]) , {arr[i] , arr[i + 1]}});
	}
	sort(v.begin() , v.end());
	for(auto it : v){
		if(find(it.second.first) != find(it.second.second)){
			ans += it.first;
			parent[find(it.second.first)] = find(it.second.second);
		}
	}
	printf("%lld\n" , ans);
}