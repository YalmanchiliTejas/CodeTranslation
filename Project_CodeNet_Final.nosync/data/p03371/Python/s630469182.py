a, b, c, x, y = map(int, input().split())

ans = float("inf")
for i in range(0, max(2*x, 2*y)+1, 2):
    na = 0 if x-i//2 < 0 else x-i//2
    nb = 0 if y-i//2 < 0 else y-i//2
    ans = min(ans, c*i + a*na + b*nb)

print(ans)
