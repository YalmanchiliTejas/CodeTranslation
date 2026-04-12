A,B,C,X,Y = map(int,input().split())
if A+B<=2*C:
  print(X*A+Y*B)
else:
  Zmin=min(X,Y)*2
  Zmax=max(X,Y)*2
  ans=float("inf")
  for i in range(Zmin,Zmax+2,2):
    ans=min(ans,C*i+max(0,X-i//2)*A+max(0,Y-i//2)*B)
  print(ans)
 