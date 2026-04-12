#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	int size;
	cin >> size;
	string arr[size];
	int ch[size][26];
	memset(ch,0,sizeof(ch));
	string k;
	for(int i = 0; i < size; i++){
		cin >> k;
		for(int j = 0; j < k.size(); j++){
			ch[i][k[j] - 'a']++;
		}
	}
	for(int j = 0; j < 26; j++){
		int min = 2e9;
		REP(i,0,size){
			if(ch[i][j] < min)
				min = ch[i][j];	
		}
		REP(z,0,min)
			cout << (char)(j + 'a');
	}
	return 0;
}

