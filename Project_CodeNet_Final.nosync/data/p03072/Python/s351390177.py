n=int(input())
h=[int(i) for i in input().split()]
maxh=0
ans=0
for i in range(n):
    if maxh<=h[i]:
        ans+=1
        maxh=h[i]
print(ans)