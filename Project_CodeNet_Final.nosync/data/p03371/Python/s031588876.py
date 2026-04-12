A,B,C,X,Y = map(int,input().split())
MIN = min(X,Y)

ans1 = A*X + B*Y
ans2 = C*max(X,Y)*2

ans = C*MIN*2
X -= MIN
Y -= MIN
ans += A*X + B*Y

print(min([ans,ans1,ans2]))

