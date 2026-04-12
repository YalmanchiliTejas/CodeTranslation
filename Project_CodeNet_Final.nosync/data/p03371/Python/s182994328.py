A, B, C, X, Y = map(int, open(0).read().split())
ans = 0
res = 0
if A + B > C * 2:
    ans += C * min(X, Y) * 2
    res = X - Y
else:
    ans += A * X + B * Y
    
if res > 0:
    ans += min(A * res, C * res * 2)
elif res < 0:
    ans += min(B * abs(res), C * abs(res) * 2)
    
print(ans)
