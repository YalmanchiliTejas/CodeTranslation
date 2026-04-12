A,B,C,X,Y=map(int,input().split())

ans=10**10
# ABピザの枚数を全探索
for i in range(0,max(X,Y)*2+1,2):
  cost=i*C
  cost+=max(X-i//2,0)*A
  cost+=max(Y-i//2,0)*B
  if cost<ans:
    ans=cost
print(ans)