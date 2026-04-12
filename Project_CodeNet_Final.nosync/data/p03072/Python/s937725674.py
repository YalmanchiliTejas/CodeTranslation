N = int(input())
H = [int(x) for x in input().split()]

ans = 1
hmax = H[0]

for i in range(1, N):
    if hmax <= H[i]:
        hmax = H[i]
        ans += 1

print(ans)