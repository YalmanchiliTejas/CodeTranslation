A,B,C,X,Y=map(int,input().split())
M=[A,B,C]

ans=[]

ans.append(A*X+B*Y)
ans.append(C*max(X,Y)*2)

if X>Y:
  ans.append(C*min(X,Y)*2+A*(X-min(X,Y)))
if Y>X:  
  ans.append(C*min(X,Y)*2+B*(Y-min(X,Y)))

print(min(ans))