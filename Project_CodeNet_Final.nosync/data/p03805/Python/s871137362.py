n,m=map(int,input().split())
AdjacencyMatrix=[[0]*n for i in [0]*n]
for i in [0]*m:
  a,b=map(int,input().split())
  AdjacencyMatrix[a-1][b-1]=1
  AdjacencyMatrix[b-1][a-1]=1
#print(AdjacencyMatrix)

def DFS(point,TFlist):
#  print(TFlist)
  if not False in TFlist:
    return 1
  ans=0
  for i in range(n):
    if not AdjacencyMatrix[point][i]:
      continue  #AMの0なら処理せず
    if TFlist[i]:
      continue  #探索済みなら処理せず
    TFlist[i]=True #探索したのでTFlistをTrue
    ans+=DFS(i,TFlist) #再帰的にansを加算
    TFlist[i]=False #枝を戻すためにTFlistをFalse
  return ans

TFlist=[True]+[False]*(n-1)
print(DFS(0,TFlist))