#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

// int dfs(int v, vector<vector<int>> A, vector<int> visit, int &count)
// {
//     bool all_flag = 1;

//     for (int i = 0; i < visit.size(); i++)
//     {

//         if (visit[i] == 0)
//         {
//             all_flag = 0;
//         }
//     }

//     if (all_flag == 1)
//     {
//         //count++;
//         return 1;
//     }

//     int mas=0;

//     for (int w : A[v])
//     {
//         if (visit[w] == 0)
//         {
      
//             visit[w] = 1;
//             mas+=dfs(w, A, visit, count);
//             visit[w] = 0;
//         }
//     }

//     return mas;
// }

// int main()
// {
//     int N, M;
//     cin >> N >> M;

//     vector<vector<int>> A(N, vector<int>(0));

//     for (int i = 0; i < N; i++)
//     {

//         int a, b;
//         cin >> a >> b;

//         A[a - 1].push_back(b - 1);
//         A[b - 1].push_back(a - 1);
//     }

//     vector<int> visit(N, 0);

//     visit[0] = 1;

//     int count = 0;
//     count =dfs(0, A, visit, count);

//     cout << count << endl;
//     return 0;
// }


const int nmax=8;
bool graph[nmax][nmax];

 int dfs(int v,int N,bool visited[nmax]){

 bool all_visited=true;

 for(int i=0;i<N;++i){
 if(visited[i]==false)
 all_visited=false;
 }

 if(all_visited){
 return 1;
 }


 int ret=0;

 for(int i=0;i<N;++i){
 if(graph[v][i]==false) continue;
 if(visited[i]) continue;

 visited[i]=true;
 ret+=dfs(i,N,visited);
 visited[i]=false;
 }

 return ret;
 }

 int main(void){
 int N,M;
 cin >> N >> M;

 for(int i=0;i<M;++i){
 int A,B;
 cin >> A >> B;
 graph[A-1][B-1]=graph[B-1][A-1]=true;
 }

 bool visited[nmax];
 for(int i=0;i<N;++i){
 visited[i]=false;
 }

 visited[0]=true;
 cout << dfs(0,N,visited) << endl;
 return 0;
 }