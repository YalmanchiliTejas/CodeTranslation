#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
#include <cctype>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;


main(){
    int n, k;
    string s;

    cin >> n >> s >> k;

    for (int i = 0; i<n; i++){
        if(s[i] != s[k-1]) s[i] = '*';
    }

    cout << s;

}

/*

    for (int i = 0; i<n; i++){

    }

*/
