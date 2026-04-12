A,B,C,X,Y=map(int,input().split())

ans=A*X+B*Y
for i in range(1,max(X,Y)+1):
  if i<=X and i<=Y:
    val=A*(X-i)+B*(Y-i)+C*2*i
    ans=min(ans,val)
  elif i>X:
    val=B*(Y-i)+C*2*i
    ans=min(ans,val)
  else:
    val=A*(X-i)+C*2*i
    ans=min(ans,val)
print(ans)