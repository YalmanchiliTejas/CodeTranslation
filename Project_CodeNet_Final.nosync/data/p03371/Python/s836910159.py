A, B, AB, X, Y = map(int,input().split())

ans = 0
if A + B < 2*AB:
    ans += min(X,Y) * (A+B)
else:
    ans += min(X,Y) * 2 * AB

X, Y = X-min(X,Y), Y-min(X,Y)

if X > 0:
    ans += min(X*A, 2*X*AB)
else:
    ans += min(Y*B, 2*Y*AB)

print(ans)