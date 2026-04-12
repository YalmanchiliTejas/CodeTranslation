a, b, c, x, y = map(int, input().split())

ans = float("inf")
for k in range(0, max(x, y)*2+1, 2):
    i = 0 if x-k//2 < 0 else x-k//2
    j = 0 if y-k//2 < 0 else y-k//2
    ans = min(ans, a*i+b*j+c*k)

print(ans)
