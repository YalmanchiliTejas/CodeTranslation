N = int(input())
H = list(map(int,input().split()))
m = H[0]
ans = 0
for h in H:
    m = max(m,h)
    if h >= m:
        ans += 1

print(ans)
