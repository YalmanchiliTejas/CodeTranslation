#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bits/stdc++.h>

using namespace std;


int main(){
    //int n, k, t, h;
    int n, A, next_add_i, last_i, cur_last_A;
    next_add_i = 0;
    cin >> n;
    vector<int> sort_curs(n);
    
     for (int i=0; i<n; i++){
        cin >> A;

        if (i == 0){
            sort_curs.at(i) = A;
            next_add_i++;
            last_i = i;
        } else{
            if (sort_curs.at(last_i) >= A){
                last_i++;
                sort_curs.at(last_i) = A;
                next_add_i++;
            } else{
                for (int sort_i=0; sort_i<=last_i; sort_i++) {
                    cur_last_A = sort_curs.at(sort_i);
                    if (cur_last_A < A){
                        sort_curs.at(sort_i) = A;
                        break;
                    }
                }
            }
        }
    }

    cout << next_add_i << endl;

    return 0;
}