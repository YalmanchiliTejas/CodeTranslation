N = int(input())
H = list(map(int, input().split()))

max_ = 0
ans = 0
for i in range(N):
    if H[i] >= max_:
        ans += 1
        max_ = H[i]

print(ans)