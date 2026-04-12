n = int(input())
h = list(map(int,input().split()))
k = h[0]
ans = 1
for i in range(1,n):
    if(h[i] >= k):
        k = h[i]
        ans += 1
print(ans)