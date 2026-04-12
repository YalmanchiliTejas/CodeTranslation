A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(10**5 + 1):
    price = 2*C*i + A*max(0, X - i) + B*max(0, Y - i)
    if ans > price:
        ans = price

print(ans)