n = int(input())
h = list(map(int,input().split()))
ans = 1
maxi = h[0]
for i in range(1,n):
    if h[i] >= maxi:
        ans += 1
    maxi = max(maxi,h[i])

print(ans)    
