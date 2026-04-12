N = int(input())
H = list(map(int,input().split()))

m_max = 0
ans = 0
for i in range(N):
    if m_max <= H[i]:
        m_max = H[i]
        ans += 1

print(ans)
