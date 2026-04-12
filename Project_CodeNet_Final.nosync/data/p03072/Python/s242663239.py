n = int(input())
h = list(map(int,input().split()))
ans = 1
k = h[0]
for i in range(1,n):
    if h[i]>=k:
        ans+=1
        k = h[i]
print(ans)