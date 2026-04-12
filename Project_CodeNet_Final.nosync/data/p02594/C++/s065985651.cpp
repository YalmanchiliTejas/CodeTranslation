#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
 
using namespace std;
typedef long long int ll;
typedef pair <int,int> pii;
typedef pair<ll,ll> pll;
 
 
/*bool compare_function(const pair<int, int> a, const pair<int, int> b)
{
    return a.first < b.first;
}*/
// use case
//sort(V.begin(), V.end(), compare_function);
 
/*struct compare
{
    bool operator ()(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second-a.first==b.second-b.first)
    {
        return a.first>b.first;
    }
    return a.second-a.first < b.second-b.first;}
};
priority_queue <pair<int,int>, vector <pair<int,int>>, compare> Q;*/
 
/*void print1(vector <int> X)
{
    for (int i=0; i<X.size(); i++)
    {
        cout<<X[i]<<" ";
    }
    cout<<endl;
    return;
}
 
void print2(vector <vector <int>> X)
{
    for (int i=0; i<X.size(); i++)
    {
    for (int j=0;j<X[i].size();j++) {
        cout<<X[i][j]<<" ";}
    cout<<endl;}
    return;
}*/

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int a;
	cin>>a;
	if (a>=30) {cout<<"Yes"<<endl;} 
	else {cout<<"No"<<endl;}
    return 0;
}
