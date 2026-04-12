n=int(input())
h=list(map(int,input().split()))
a=[]
ans=0
for i in range(n):
    a.append(h[i])
    if max(a) == h[i]:
        ans+=1
print(ans)