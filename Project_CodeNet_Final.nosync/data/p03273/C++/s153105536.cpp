/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int h,w;
    cin>>h>>w;
    char x[h][w];
    
    forn(i,h){
        forn(j,w)   cin>>x[i][j];
    }
    
    bool col[w] = {false};
    bool row[h] = {false};

    forn(i,h){
        bool flag = true;
        forn(j,w){
            if(x[i][j]=='#'){
                flag= false;
                break;
            }
        }
        if(flag){
            //cout<<"---\n";
            //cout<<i<<endl;
            row[i] = true;
        }
    }

    forn(j,w){
        bool flag = true;
        forn(i,h){
            if(x[i][j]=='#'){
                flag = false;
                break;
            }
        }
        if(flag){
            //cout<<"---\n";
            //cout<<j<<endl;
            col[j] = true;
        }
    }
   /* 
    cout<<"The columns are\n";
    forn(i,w)   cout<<i<<" "<<col[i]<<endl;
    cout<<"The rows are\n";
    forn(i,h)   cout<<i<<" "<<row[i]<<endl;
*/
    forn(i,h){
        forn(j,w){
            if(row[i] && col[j]){
                break;
            }
            if(row[i] || col[j]){
                if(j==w-1) cout<<"\n";
                continue;
            }    
            cout<<x[i][j];
            if(j==w-1)  cout<<"\n";
        }
    }
    return 0;
}

