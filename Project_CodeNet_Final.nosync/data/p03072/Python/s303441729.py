n=int(input())
h=list(map(int,input().split()))
ans=0
for i in range(n):
    c=0
    for j in range(i):
        if h[i]<h[j]:
            c=1
            break
    if c==0:
        ans+=1
print(ans)