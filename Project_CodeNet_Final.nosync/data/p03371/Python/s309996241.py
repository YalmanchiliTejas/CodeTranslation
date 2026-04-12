A, B, C, X, Y = [int(x) for x in input().split()]
ans = 0
#A, Bを1枚ずつ同時
if A + B >= 2 * C:
    c = min(X, Y)
    ans += c * 2 * C
    X -= c
    Y -= c

if 2 * C <= A:
    ans += 2 * C * X
else:
    ans += A * X

if 2 * C <= B:
    ans += 2 * C * Y
else:
    ans += B * Y

print(ans)