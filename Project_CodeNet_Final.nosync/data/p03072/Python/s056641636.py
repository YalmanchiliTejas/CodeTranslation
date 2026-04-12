N = int(input())
H = list(map(int, input().split()))

ans = 0
height = 0
for i in range(N):
    if height <= H[i]:
        ans += 1
        height = H[i]
print(ans)