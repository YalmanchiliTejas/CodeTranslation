#include <iostream>
#include <vector>
using namespace std;

string k;
int d;

int MAX = 1e9+7;

vector<vector<vector<int>> > records;

int dispatch(int number, int mod, bool smaller){

//cout << "*" << number << "(" << mod << ")(" << smaller << ")\n";

    if(number == (int)k.length()){
        if(mod == 0)
            return 1;
        else
            return 0;
    }

    if(records[number][mod][smaller] != -1)
        return records[number][mod][smaller];

    int sum = 0;
    int max_digit = (smaller)?9:(k[number]-'0');
    for(int digit = 0; digit <= max_digit; digit++){
        bool compared = true;
        if(!smaller && (digit == (k[number]-'0')))
            compared = false;
        int new_mod = mod - digit;
        while(new_mod < 0)
            new_mod += d;
//cout << "number=" << number << " digit=" << digit << "compared=" << compared << "\n";
        (sum += dispatch(number+1, (new_mod%d), compared)) %= MAX;
    }

    records[number][mod][smaller] = sum;
//cout << "number=" << number << " mod=" << mod << " smaller=" << smaller << " sum=" << sum << "\n";
    return sum;
}

/*
int dispatch(){
    int size = k.length();

    for(int number = 0; number < size; number++){
        for(mod = 0; mod < d; mod++){
            for(int exceed = 0; exceed < 2; exceed++){

                record[number][mod][exceed] = record[number-1][][]
            }
        }
    }

    return 0;
}
*/

int main(){
    cin >> k >> d;

    records = vector<vector<vector<int>>>(k.length(), vector<vector<int>>(d, vector<int>(2, -1)));
    int result = dispatch(0, 0, false);

    cout << (result+MAX-1)%MAX << "\n"; //exclude 0

    return 0;
}
