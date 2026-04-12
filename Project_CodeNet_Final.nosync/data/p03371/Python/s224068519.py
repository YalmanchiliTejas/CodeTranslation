A, B, C, X, Y = map(int, input().split())

pizza = {X : A, Y : B}
ans = 0

for i in range(max(X, Y)):
    if i <= min(X, Y) - 1:
        ans += min(A + B, 2 * C)
    else:
        ans += min(pizza[max(X, Y)], 2 * C)

print(ans)