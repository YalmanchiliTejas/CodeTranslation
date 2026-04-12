N = int(input())
H = list(map(int, input().split()))
high = 0
ans = 0

for i in range(N):
    if H[i] >= high:
        high = H[i]
        ans += 1

print(ans)