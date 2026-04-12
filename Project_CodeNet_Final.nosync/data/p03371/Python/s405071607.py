A,B,C,X,Y=map(int,input().split())

ans1=max(X,Y)*C*2
ans2=X*A+Y*B
if X>Y:
  ans3=C*Y*2+(X-Y)*A
else:
  ans3=C*X*2+(Y-X)*B

print(min(ans1,ans2,ans3))