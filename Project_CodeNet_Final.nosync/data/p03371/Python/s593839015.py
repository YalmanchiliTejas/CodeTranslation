A,B,C,X,Y=map(int,input().split())
ans=5000*(10**5)*2+1

for i in range(max(X,Y)+1):
  total=0
  total=2*C*i+A*max(X-i,0)+B*max(Y-i,0)
  if ans>=total:
    ans=total
print(ans)