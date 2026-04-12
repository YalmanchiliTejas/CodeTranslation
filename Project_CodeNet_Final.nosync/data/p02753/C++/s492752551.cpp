#include "bits/stdc++.h"
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define gcd(ade,bde) __gcd(ade,bde)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define pb(ade) push_back(ade)
#define pp pop_back()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define type(ade) typeid(ade).name();
#define starting() auto start = high_resolution_clock::now()
#define ending() auto stop = high_resolution_clock::now();\
auto duration = duration_cast<microseconds>(stop - start);\
cerr << "\n" << "\n" << "Execution Time : "<< duration.count()/1000 << " ms" << "\n"

template <typename T1>
void print(vector<T1> arr) {
	int l = (int)arr.size();
	cerr << "[" ;
	for(int i = 0; i < l; i++) { 
		(i == l - 1) ? cerr << arr[i] : cerr << arr[i] << "," ;
	}
	cerr << "]" << "\n";
}

template <typename T1>
void printArr(int arr[], int l) {
	cerr << "[" ;
	for (int i = 0; i < (int)l; i++) { 
		(i == l-1) ? cerr << arr[i] : cerr << arr[i] << "," ;
	}
	cerr << "]" << "\n";
}

template <typename T1>
void console(vector<vector<T1>> arr) {
	for (int i = 0; i < (int)arr.size(); ++i) { 
		cerr << "\n" << " [" ; 
	    for(int j = 0; j < (int)arr[i].size(); ++j) { 
			(j == (int)arr[i].size() - 1) ? cerr << arr[i][j] : cerr << arr[i][j] << "," ;
		}
	    cerr << "]";
	} 
	cerr << "\n";
} 
template <typename T1,typename T2>
void mapped(map<T1,T2> m) { 
	for(auto ite = m.begin(); ite != m.end(); ++ite){ 
		cerr << "'" << ite->first << "'"<< " : " << ite->second << "\n";
	}
}
 
template <typename T1 , typename T2>
void mappedArr(map<T1,vector<T2>> m) {
	for (auto ity = m.begin(); ity != m.end(); ++ity) {
		cerr << "'" << ity->first << "'" << " : " << "[";
        for (int i = 0; i < (int)ity->second.size(); ++i) {
			(i == (int)ity->second.size() - 1) ? cerr << ity->second[i] : cerr << ity->second[i] << ",";
		}
		cerr << "]" << "\n";
	}
}
	 
string int_to_string(int x) {
	stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}
int char_to_int(char c) {
	int n = (int)c - 48;
	return n;
}
int string_to_int(string x) {
	int n;
	stringstream s(x);
	s >> n;
	return n;
}
 
template <typename T1, typename T2>
void vectPair(vector<pair<T1,T2>> vp) {
	for (int arrp = 0; arrp< (int)vp.size(); ++arrp){
		cerr << "(" << vp[arrp].first << "," << vp[arrp].second << ")" << "\n" ;
	}
}

//unordered_map<int,int> um;
//unordered_set<int> us;
//set<int> s;
// v.front() gives the first element of vector
// v.back()  gives the last element of vector
// insert erase substr
//g++ -o Legendary-Grandmaster Legendary-Grandmaster.cpp&Legendary-Grandmaster.exe
//cd C:\Users\158si\Desktop\Algorithim\codeForces\elite
// for-bash cd C:/Users/158si/Desktop/Algorithim/codeForces/elite
//memset(arr,element,sizeofarray);//Converts the value ch to unsigned char and copies it
// into each of the first n characters of the object pointed to by str[].
//g++ -o impulse.exe impulse.cpp
//puts
/*
	ifstream infile("input.txt");
	//infile.open("input.txt");
	if(infile.fail()){
		cout << "File cannot be linked";
		return 0;
	}
	int n;
	infile >> n;
	cout << 2*n;
	infile.close(); 
*/


//**************************************************************  
const ll mod = 1e9 + 7;
const ll INF = 1e18L + 5;

vector<vector<int>> a;
vector<int> p;

void prum(int n, vector<bool>& check) {

	//if((int)p.size() > n){
	//	return ;
	//}
	if((int)p.size() == n) {
		a.push_back(p);
		//print<int> (p);
		//cout << "yes";
		return ;
	}else{
		for (int i = 0; i < n; ++i) {
			if (!check[i]) {
				check[i] = 1;
				p.push_back(i + 1);
				prum(n,check);
				p.pop_back();
				check[i] = 0;
				//p.push_back(i + 1);
				if ((int)p.size() > 0) {
					prum(n,check);
					p.pop_back();
				}
		    }
		}
	}
	//cout << "cool";
} 
//this is done when we dont want repetition
//check[i] = 1;
//p.push_back(i + 1);
//prum(n,check);
////p.pop_back();
//check[i] = 0;
////p.push_back(i + 1);
////prum(n,check);
//p.pop_back();

int main(){
	IOS; 
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB"){
		cout << "No";
	}else {
		cout << "Yes";
	}
  	return 0;
}






















