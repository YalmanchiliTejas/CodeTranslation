from itertools import permutations
N,M=map(int,input().split())
G=[[] for _ in range(N)]
 
for i in range(M):
    a,b=map(int,input().split())
    G[a-1].append(b-1)            #ペアのリストに格納、a=1,b=7ならb=7をリスト0に格納
    G[b-1].append(a-1)            #ペアのリストに格納、a=1,b=7ならa=1をリスト6に格納
  
P=permutations(range(0,N),N)      #(リスト,順列の要素の数)
ans=0

for A in P:
  if A[0]!=0:                     #先頭が1でなければ下は実行されずに次のループへ
    continue
  for i in range(N-1):
    if not (A[i+1]  in G[A[i]]):
      break
  else:
    ans += 1
print(ans)