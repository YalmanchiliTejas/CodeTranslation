N = int(input())
H = list(map(int, input().split()))
ans = 1
hgt = H[0]

for i in range(1, N):
    if hgt <= H[i]:
        ans += 1
        hgt = H[i]

print(ans)