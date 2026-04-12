A,B,C,X,Y=map(int,input().split())
ans=A*X+B*Y
for i in range(max(X,Y)*2+1):
  if(i%2==0):
    ans=min(ans,A*max(0,X-i//2)+B*max(0,Y-i//2)+C*i)
print(ans)