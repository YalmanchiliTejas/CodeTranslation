N = int(input())
H = [int(i) for i in input().split()]

ans = 1
p = H[0]
for i in range(1,N):
    if p <= H[i]:
        ans += 1
        p = H[i]

print(ans)
