n=int(input())
h=list(map(int, input().split()))
ans=1
b=0
for i in range(1,n):
        b=max(h[j] for j in range(i))
        if b<=h[i]:
            ans+=1
print(ans)