n,H = int(input()),list(map(int,input().split()))

h = H[0]
ans = 1
for i in range(1,n):
    if h <= H[i]:
        h = H[i]
        ans += 1
print(ans)