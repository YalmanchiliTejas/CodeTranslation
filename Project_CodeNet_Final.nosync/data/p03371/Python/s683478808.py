A,B,C,X,Y=map(int,input().split())
if A>=2*C:
  if B>=2*C:
    print(2*C*max(X,Y))
    exit()
  else:
    print(2*C*X+B*max(0,(Y-X)))
    exit()
elif B>=2*C:
  print(2*C*Y+A*max(0,(X-Y)))
  exit()
else:
  ans=A*X+B*Y
  for i in range(1,min(X,Y)+1):
    p=A*(X-i)+B*(Y-i)+2*C*i
    ans=min(ans,p)
  print(ans)