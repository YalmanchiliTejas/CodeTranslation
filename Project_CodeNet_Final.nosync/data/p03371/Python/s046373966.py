A, B, C ,X, Y = map(int, input().split())

ans = 10 ** 20
for i in range(max(X, Y)+1):
    kari = 2*i*C + A*max(0, (X-i)) + B*max(0, (Y-i))
    ans = min(ans, kari)

print (ans)
