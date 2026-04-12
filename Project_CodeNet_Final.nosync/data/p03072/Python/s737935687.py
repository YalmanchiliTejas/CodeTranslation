N = int(input())
H = list(map(int,input().split()))
ans = 0
m = 0
for i in range(N):
    if m <= H[i]:
        ans += 1
    m = max(m,H[i])
print(ans)