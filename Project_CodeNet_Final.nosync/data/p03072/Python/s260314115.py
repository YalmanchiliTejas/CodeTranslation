n = int(input())
*H, = map(int, input().split())
m = 0
ans = 0
for h in H:
    if h >= m:
        ans += 1
        m = h
print(ans)
