A, B, C, X, Y = map(int, input().split())

ans = A*X + B*Y

i = 1
while True:
    cost = A*max(X-i, 0) + B*max(Y-i, 0) + 2*C*i
    if cost > ans:
        break
    ans = min(cost, ans)
    i += 1

print(ans)