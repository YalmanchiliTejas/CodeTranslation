n=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(n):
    ans1=0
    for j in range(0,i+1):
        if h[i]>=h[j]:
            ans1+=1
        if ans1==i+1:
            ans+=1
print(ans)