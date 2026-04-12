A,B,C,X,Y=map(int,input().split())
ans= min(A+B,2*C)*min(X,Y)
if X>Y:
  ans+=min(A,2*C)*(X-Y)
else:
  ans+=min(B,2*C)*(Y-X)
print(ans)
