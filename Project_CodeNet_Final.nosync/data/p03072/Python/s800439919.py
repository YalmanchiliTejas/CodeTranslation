n=int(input())
h=list(map(int,input().split()))

ans=0
c=0
for i in range(n):
        if c<=h[i]:
                ans+=1
                c=h[i]

print(ans)