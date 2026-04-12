N = int(input())
H = [int(x) for x in input().split()]
ans = 0
height = 0
for i in range(N):
    if height <= H[i]:
        ans += 1
        height = H[i]
print(ans)
