A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(2*10**5+1):
    price = C * i + max(0, X - i // 2) * A + max(0, Y - i // 2) * B
    ans = min(ans, price)
print(ans)