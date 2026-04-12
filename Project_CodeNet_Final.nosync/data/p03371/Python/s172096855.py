A, B, C, X, Y = map(int, input().split())

N = max(X,Y)
ans = 10**10

for i in range(2*N+1):
    price = C * i + A * max(0,X-i//2) + B * max(0,Y-i//2)
    ans = min(ans,price)

print(ans)