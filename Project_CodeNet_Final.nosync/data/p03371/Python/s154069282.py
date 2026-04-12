# https://atcoder.jp/contests/abc095/tasks/arc096_a

A,B,C,X,Y = map(int,input().split())

ans = 0

# MINXY個ずつ買う
MINXY = min(X,Y)
if A+B <= 2 * C:
    ans += (A+B) * MINXY
else:
    ans += (2 * C) * MINXY

X -= MINXY
Y -= MINXY

# 買い忘れを買う
if X == 0:
    if B <= 2 * C:
        ans += B * Y
    else:
        ans += (2 * C) * Y
else:
    if A <= 2 * C:
        ans += A * X
    else:
        ans += (2 * C) * X

print(ans)