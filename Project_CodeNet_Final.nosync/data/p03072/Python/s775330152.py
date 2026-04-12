N = int(input())
H = list(map(int, input().split()))
h = H[0]
ans = 0
for i in range(N):
    if h <= H[i]:
       ans += 1
       h = H[i]

print(ans)