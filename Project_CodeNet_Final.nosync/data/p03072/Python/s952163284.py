N = int(input())
*H, = map(int, input().split())

v = 0
ans = 0
for i in range(N):
    if v <= H[i]:
        ans += 1
    v = max(v, H[i])
print(ans)