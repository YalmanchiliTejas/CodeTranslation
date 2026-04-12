A,B,C,X,Y = map(int,input().split())

ans = 10**12
for c in range(max(X,Y) + 1):
    cost = C*2*c
    a = max(0, X-c)
    b = max(0, Y-c)
    cost += A*a + B*b
    ans = min(cost, ans)
print(ans)