N = int(input())
H = list(map(int, input().split()))

ans = 1
height = H[0]
for i in range(1, N):
    if height <= H[i]:
        ans += 1
        height = H[i]
print(ans)