#include <bits/stdc++.h>
using namespace std;

string fb[10001];

int main() {

    for(int i=1;i<10001;i++){
        if(i%15==0){
            fb[i] = "FizzBuzz";
        }
        else if(i%3==0){
            fb[i] = "Fizz";
        }
        else if(i%5==0){
            fb[i] = "Buzz";
        }
        else{
            stringstream ss;
            ss << i;
            ss >> fb[i];
        }
    }

    while(1){

        int m,n;

        scanf(" %d %d",&m,&n);

        if( m == 0 && n == 0){
            break;
        }

        list<int> l;

        for(int i=1; i<= m; i++){
            l.push_back(i);
        }

        list<int>::iterator itr = l.begin();

        for(int i=1; i<=n; i++){

            string s;

            cin >> s;

            if(l.size() == 1){
                continue;
            }

            if(s != fb[i]){
                list<int>::iterator itmp = itr;
                itr++;
                l.erase(itmp);
            }else{
                itr++;
            }

            if(itr == l.end()){
                itr = l.begin();
            }

        }

        if(l.size() != 0) {

            itr = l.begin();

            cout << *itr;

            itr++;

            for (; itr != l.end(); itr++) {
                cout << ' ' << *itr;
            }

            cout << endl;

        }

    }

    return 0;
}