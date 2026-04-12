N = int(input())
H = list(map(int, input().split()))

M = H[0]
ans = 0
for h in H:
    if h < M:
        continue
    ans += 1
    M = h

print(ans)
