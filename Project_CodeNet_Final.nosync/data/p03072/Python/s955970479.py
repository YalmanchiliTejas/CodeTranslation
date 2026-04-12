n=int(input())
h=list(map(int, input().split()))

ans=1
for i in range(n-1):
    m=max(h[0:i+1])
    if h[i] <= h[i+1] and m <= h[i+1]:
        ans+=1

print(ans)
