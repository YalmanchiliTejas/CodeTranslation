#include "bits/stdc++.h"

using namespace std;

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))
#define OUT(P) cout << (P) << endl
#define OUT2(P1, P2) cout << (P1) << " " << (P2) << endl
#define PRINT_ARRAY(P) for(int i=0; i<P.size(); i++) cout << P[i] << endl;

// integerの各桁を足す
int sum_digits(int num);

bool will_be_deleted(string items) {
    bool rtn = true;
    for(int i=0; i<items.size(); i++) {
        if(items[i] == '#') rtn = false; 
    }
    return rtn;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    vector<bool> is_deleted_columns(h, true);
    vector<bool> is_deleted_rows(w, true);
    
    for(int i=0; i<h; i++) {
        cin >> a[i];
    }

    for(int i=0; i<h; i++) {
        is_deleted_columns[i] = !will_be_deleted(a[i]);
    }
    for(int i=0; i<w; i++) {
        string row = "";
        for(int j=0; j<h; j++) {
            row += a[j][i];
        }
        is_deleted_rows[i] = !will_be_deleted(row);
    }
    
    for(int i=0; i<h; i++) {
        bool new_line_flg = false;
        for(int j=0; j<w; j++) {
            if(is_deleted_columns[i] && is_deleted_rows[j]) {
                cout << a[i][j];
                new_line_flg = true;
            }
        }
        if(new_line_flg) cout << endl;
    }
     
    return 0;
}

/******************************/
/***** DECRARED FUNCTIONS *****/
/******************************/

// integerの各桁を足す
int sum_digits(int num) {
    int rtn = 0;
    string num_str = to_string(num);
    for(int i=0; i<num_str.size(); i++) {
        rtn += num_str[i] - '0';
    }   
    return rtn;
}

