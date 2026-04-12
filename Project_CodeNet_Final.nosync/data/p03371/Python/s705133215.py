A,B,AB,X,Y=map(int,input().split())
ans1=A*X+B*Y
ans2=2*AB*max(X,Y)
if X<Y:
    ans3=2*AB*X+B*(Y-X)
else:
    ans3=2*AB*Y+A*(X-Y)
print(min(ans1,ans2,ans3))
