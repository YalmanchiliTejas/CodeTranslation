/*Shivam Bhalla */
/* f2016941@pilani.bits-pilani.ac.in */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
long long maxv = 1e9;


int main(){
	int N;
	cin>>N;
	vector<int>arr(N);
	for(int i=0;i<N;i++)
		cin>>arr[i];
	int count=1;
	int maxH=arr[0];
	for(int i=1;i<N;i++){
		if(arr[i]>=maxH){
			count+=1;
			maxH=arr[i];
		}
	}
	cout<<count;	
    return 0;
}
