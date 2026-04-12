N = int(input())
H = [int(i) for i in input().split()]

ans = 1
m = H[0]

for i in range(1,N):
    if H[i] >= m:
        ans += 1
        m = H[i]

print(ans)
