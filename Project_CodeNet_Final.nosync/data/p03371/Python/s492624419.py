# https://atcoder.jp/contests/abc095/tasks/arc096_a

A, B, C, X, Y = list(map(int, input().split(" ")))

cost = 0
if A + B > 2 * C:
    cost += min(X, Y) * C * 2
    if X > Y:
        cost += (X - Y) * min(A, C*2)
    else:
        cost += (Y - X) * min(B, C*2)
else:
    cost += X * A + Y * B

print(int(cost))
