A, B, C, x, y = map(int, input().split())

if x > y:
    ans = min(A+B, 2*C) * y
    ans += min(A, 2*C) * (x-y)
elif x < y:
    ans = min(A+B, 2*C) * x
    ans += min(B, 2*C) * (y-x)
else:
    ans = min(A+B, 2*C) * x
print(ans)