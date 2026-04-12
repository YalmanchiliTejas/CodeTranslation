#include <iostream>
#include <string>
#include <vector>

unsigned int count = 0;
std::vector<std::vector<unsigned int> > graph;
std::vector<bool> visited;

void solve(unsigned int index){

bool flg = true;

for (auto it = graph[index].begin(); it != graph[index].end(); ++it){
if (visited[*it]){
continue;
}

flg = false;

visited[*it] = true;
solve(*it);
visited[*it] = false;

}

if (flg){

for (unsigned int i = 0; i < visited.size(); ++i){
if (!visited[i]){
return;
}
}

++count;

}

}

int main(){
unsigned int N, M;
std::string line;

std::cin >> N >> M;
std::getline(std::cin, line);

for (unsigned int i = 0; i < N; ++i){
graph.push_back(std::vector<unsigned int>());
visited.push_back(false);
}

for (unsigned int i = 0, a, b; i < M; ++i){
std::cin >> a >> b;
std::getline(std::cin, line);
graph[a-1].push_back(b-1);
graph[b-1].push_back(a-1);
}

visited[0] = true;
solve(0);

std::cout << count << std::endl;

return 0;
}
