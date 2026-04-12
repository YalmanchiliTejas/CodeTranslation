n = int(input())
h = list(map(int, input().split()))
hest = h[0]
ans = 1
for i in range(n-1):
    if h[i+1] >= hest:
        hest=h[i+1]
        ans += 1

print(ans)