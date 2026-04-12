#include<bits/stdc++.h>
using namespace std;
int N,M;

string name[2003];
vector<int> G[2003];
int Gr[2003];

vector<string> cut_s(const string &s ){
  vector<string> v;
  int k=1;
  for(int i=1;i<(int)s.size();i++){
    if(s[i] == '/' ){
      v.push_back( s.substr(k,i-k) );
      k = i+1;
    }
  }
  v.push_back( s.substr(k) );
  return v;
}

int search(const vector<string> &s){
  int id = 0;
  for(int i=0;i<(int)s.size();i++){
    // cout << s[i] << " "<< id << " "<< name[id] << endl;
    bool f = false;
    if( s[i] == "." ){
      if( G[id].empty() ) return -1;
      continue; 
    }
    if( s[i] == ".." ){
      if( Gr[id] == -1 || G[id].empty() ) return -1;
      id = Gr[id];
      continue;
    }
    if( s[i] == "" ){
      if( G[id].empty() ) return -1;
      for(int j=0;j<(int)G[id].size();j++){
        int to = G[id][j];
        if( name[to] == "index.html" && G[to].empty() ) {
          id = to;
          f = true;
          break;
        }
      }
      if( !f ) return -1;
      continue;
    }
    
    for(int j=0;j<(int)G[id].size();j++){
      int to = G[id][j];
      if( name[to] == s[i] ) {
        id = to;
        f = true;
        break;
      }
    }
    if(!f) return -1;
  }
  //   cout << "last " << id << " " << name[id] << " "<< G[id].size() <<  endl;
  if( G[id].empty() ) return id;
  for(int i=0;i<(int)G[id].size();i++){
    int to = G[id][i];
    if( name[to] == "index.html" && G[to].empty() ) return to;
  }
  return -1;
}

int main(){
  while( cin >> N >> M && (N||M) ){
    int cnt = 0;

    memset(Gr,-1,sizeof(Gr));
    for(int i=0;i<=2000;i++) name[i] = "----";
    for(int i=0;i<=2000;i++) G[i].clear();

    for(int i=0;i<N;i++){
      string s; cin >> s;
      vector<string> c = cut_s( s );
      int id = 0;
      for(int i=0;i<(int)c.size();i++){
        bool f = false;
        for(int j=0;j<(int)G[id].size();j++){
          int to = G[id][j];
          if( name[to] == c[i] ) {
            id = to; f = true; break;
          }
        }
        if( f ) continue;
        
        G[id].push_back( ++cnt );
        Gr[cnt] = id;
        name[cnt] = c[i];
        id = cnt;

      }      
    }

    for(int i=0;i<M;i++){
      string s1, s2; cin >> s1 >> s2;
      vector<string> c1 = cut_s(s1);
      vector<string> c2 = cut_s(s2);
      int id1 = search(c1), id2 = search(c2);
      //  cout <<id1 << " - " << id2 << endl;
      if( id1 == -1 || id2 == -1 ) cout << "not found" << endl;
      else if( id1 != id2 ) cout << "no" << endl;
      else cout << "yes" << endl;
    }

  }
}