#include <bits/stdc++.h>

using namespace std;
vector <pair<int,int>> tab;
bool comp( pair <int,int> a , pair < int,int> b){
return (a.first < b.first);
}
int main () {
int n;
cin >> n;
int a;
for( int i = 1 ; i <= n ; i++){
    cin >> a;
    tab.push_back(make_pair(a,i));
}
sort(tab.begin(),tab.end(),comp);
int rez[200001];
for ( int i = 0 ; i < n ; i++){
    if( i < n/2){
        rez[tab[i].second]=tab[n/2].first;
    }else{
        rez[tab[i].second]=tab[(n-2)/2].first;
    }
}
for ( int i = 1 ; i <= n ; i++){
    cout << rez[i] << endl;
}
return 0;
}
