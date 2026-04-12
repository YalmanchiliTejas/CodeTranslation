#include <iostream>
#include <set>
#include <stack>

struct state{
  std::set<int> visited;
  int last;
};

bool adjacent[10][10] = {};

int main(void){
  int n, m;
  std::cin >> n >> m;

  for(int i=0; i<m; i++){
    int a, b;
    std::cin >> a >> b;
    adjacent[a][b] = true;
    adjacent[b][a] = true;
  }

  /**
  for(int i=1; i<=m; i++){
    for(int j=1; j<=m; j++){
      std::cout << adjacent[i][j] << " ";
    }
    std::cout << std::endl;
  }
  **/

  int count = 0;
  std::stack<state> st;
  state s;
  s.last=1;
  s.visited.insert(s.last);
  st.push(s);
  while(!st.empty()){
    state s = st.top();
    //std::cout << s.last << " " << s.visited.size() << std::endl;
    st.pop();
    if(s.visited.size() == n){
      count++;
    }

    for(int i=1; i<=n; i++){
      if(adjacent[s.last][i] && s.visited.find(i) == s.visited.end()){
        state new_s;
        new_s.last = i;
        new_s.visited = s.visited;
        new_s.visited.insert(i);
        st.push(new_s);
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}