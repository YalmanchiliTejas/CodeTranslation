n = int(input())
h = list(map(int,input().split()))
ans = 1
mxm = h[0]
for i in range(1,n):
    if h[i] >= mxm:
        ans += 1
        mxm = h[i]
print(ans)