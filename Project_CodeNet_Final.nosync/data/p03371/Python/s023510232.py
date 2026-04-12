A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(0, 10**5+1):
    ans = min(ans, 2*C*i + A*max(0, X-i) + B*max(0, Y-i))
print(ans)
