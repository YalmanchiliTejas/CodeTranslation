n,m=list(map(int,input().split()))
# 再帰の深さが1000を超えそうなときはこれをやっておく
import sys
sys.setrecursionlimit(10**7)

#隣接行列表現
es=[[0 for i in range(n)] for j in range(n)]
for i in range(m):
  a,b=list(map(int,input().split()))
  es[a-1][b-1]=1
  es[b-1][a-1]=1

  
#深さ優先探索

def dfs(v,visited):
  ans=0
  
  #自分が今いるところは探索済にする
  visited[v-1]=1
 
  #全部探索できたことになる
  if visited==check:
    visited[v-1]=0
    return 1
  
  #vから行けるところを考える
  for i in range(n):
    #道があって未訪問
    if visited[i]==0 and es[v-1][i]==1:
      ans=ans+dfs(i+1,visited)
  #次の探索のため未訪問にしておく
  visited[v-1]=0
   
  return ans





visited=[0 for i in range(n)]
check=[1 for i in range(n)]
print(dfs(1,visited))






      

  