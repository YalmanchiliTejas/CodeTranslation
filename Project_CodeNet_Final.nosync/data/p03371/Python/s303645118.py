A,B,C,X,Y=map(int,input().split())
ans=[]
ans.append(max([X,Y])*2*C)
ans.append(A*X+B*Y)
t=min([X,Y])*2*C
if X>=Y:
  t+=(X-Y)*A
else:
  t+=(Y-X)*B
ans.append(t)
print(min(ans))