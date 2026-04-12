A,B,C,X,Y = map(int,input().split())
ans1 = X * A + Y * B
ans2 =max(X, Y) * 2 * C
if X > Y:
    ans3 = 2 * C * Y + A * (X - Y)
else:
    ans3 = 2 * C * X + B * (Y - X)
print(min(ans1,ans2,ans3))