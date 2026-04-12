N = int(input())
H = list(map(int, input().split()))
max_ = H[0]
ans = 0
for i in range(1,N):
    if max_ <= H[i]:
        ans += 1
        max_ = H[i]
print(ans+1)