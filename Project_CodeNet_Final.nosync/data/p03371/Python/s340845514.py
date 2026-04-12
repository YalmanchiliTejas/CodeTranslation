A,B,C,X,Y = map(int,input().split())
ans1 = 0
ans2 = 0
ans1 = X*A+B*Y
ans2 = min(X,Y)*C*2
ans3 = max(X,Y)*C*2
if X>Y:
    ans2+=(X-Y)*A
elif Y>X:
    ans2+=(Y-X)*B
print(min(ans1,ans2,ans3))