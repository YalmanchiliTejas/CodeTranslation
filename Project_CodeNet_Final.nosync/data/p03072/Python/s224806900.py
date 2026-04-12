n=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(n):
    for k in range(i):
        if h[i]<h[k]:
            ans+=1
            break
Ans=n-ans
print(Ans)