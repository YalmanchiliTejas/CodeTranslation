n=int(input())
h=list(map(int,input().split()))
mh = 0
ans = 0
for i in range(n):
    if mh <= h[i]:
        ans += 1
        mh = h[i]
print(ans)