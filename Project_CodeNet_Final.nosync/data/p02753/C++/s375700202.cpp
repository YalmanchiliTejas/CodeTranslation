#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 
//#define int long long
#define MOD 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, szof(x))
#define sortall(x) sort(aint(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626 
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<int, int> pt;
//https://tradingeconomics.com/forecast/stock-market

signed main() {

	fastio();
	//#define LOCAL_DEFINE	
	#ifdef LOCAL_DEFINE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	auto a=s.find('A');
	auto b=s.find('B');
	if(a!=string::npos && b!=string::npos)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}

// https://github.com/FatihSevbanUyanik/Caltech-UCSD-Birds-PyTorch
// https://github.com/zctpig/Caltech-UCSD-Birds-200-2011/blob/master/%E2%80%9C%E2%80%9Cpytorch_caltech_birds_classification_ipynb%E2%80%9D%E7%9A%84%E5%89%AF%E6%9C%AC%E2%80%9D%E7%9A%84%E5%89%AF%E6%9C%AC.ipynb
// https://github.com/vinodjatav/Bird-Identification-using-ResNet50/blob/master/Bird_Identification_ResNet50_final_correct_model.ipynb
// https://github.com/AdrienBenamira/bird_classification_MVAchallenge
// https://www.kaggle.com/c/mva-recvis-2018/leaderboard
// https://github.com/Louis-Verret/mva-pixel2mesh
// https://github.com/bdvllrs/bird-classification-recvis

