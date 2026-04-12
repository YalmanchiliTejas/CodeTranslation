#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::vector<char> v(100000);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> v[i];
    }

    for(int i=0;i<n-1 ;i++){
    	if(v[i] == 'F' && v[i+1] == 'F') v[i+1] = 'T';
    }

   	cout << v[n-1] << endl;

}
