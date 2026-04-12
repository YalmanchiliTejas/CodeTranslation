A, B, C, X, Y = map(int,input().split())
Z = max(2*X, 2*Y)
ans = 10 ** 9
for z in range(0, Z+2, 2):
    ans = min(ans, A * max(0, X-z//2) + B * max(0, Y-z//2) + C * z)
print(ans)