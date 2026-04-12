N = int(input())
H = list(map(int,input().split()))
m = 0
ans = 0
for i in range(N):
    if H[i] >= m:
        ans += 1
        m = H[i]
print(ans)