A, B, C, X, Y = map(int, input().split())

res = float('inf')
for c in range(10**5+1):
    a = X-c
    b = Y-c
    cost = C*c*2
    cost += max(a,0)*A
    cost += max(b,0)*B
    res = min(res, cost)
print(res)