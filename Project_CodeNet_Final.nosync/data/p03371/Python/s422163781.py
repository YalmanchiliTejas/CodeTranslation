A, B, C, X, Y = list(map(int, input().split()))

ans = 0
numab = min(X, Y)
if C * 2 < A + B:
    ans += numab * C * 2
else:
    ans += numab * (A + B)

if X < Y:
    if C * 2 < B:
        ans += (Y - X) * C * 2
    else:
        ans += (Y - X) * B
else:
    if C * 2 < A:
        ans += (Y - X) * C * 2
    else:
        ans += (X - Y) * A

print(ans)
