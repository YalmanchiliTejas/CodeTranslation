A,B,C,X,Y=map(int,input().split())
#print(A,B,C,X,Y)
M=max(X,Y)*2
ans=float('inf')
for i in range(M+1):
  x=max(0,X-i//2)
  y=max(0,Y-i//2)
  #x=max(0,X-(-(-i//2)))
  #y=max(0,Y-(-(-i//2)))
  tmp=A*x+B*y+C*i
  if ans>tmp:
    ans=tmp
print(ans)