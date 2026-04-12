A, B, AB, X, Y = map(int,input().split())
AB *= 2

ans = 10**18
for i in range(max(X,Y)+1):
    cost = i * AB
    if i < X:
        cost += A * (X-i)
    if i < Y:
        cost += B * (Y-i)
    ans = min(ans, cost)

print(ans)