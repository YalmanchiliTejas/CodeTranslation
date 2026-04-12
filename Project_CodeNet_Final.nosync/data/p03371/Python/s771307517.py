A,B,C,X,Y = map(int,input().split())

ans = A * X + B * Y

if X>=Y:
    ans1 = C * Y *2 + A * (X-Y)
    ans2 = C * X * 2
else:
    ans1 = C * X * 2 + B * (Y-X)
    ans2 = C * Y *2

print(min(ans, ans1,ans2))