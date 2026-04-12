n=int(input())
h=list(map(int, input().split()))
ans=1
b=h[0]
for i in range(1,n):
        b=max(b,h[i-1])
        if b<=h[i]:
            ans+=1
print(ans)