n=int(input())
h=[int(i) for i in input().split()]
pre=[0]
for i in range(len(h)):
    pre.append(max(pre[-1],h[i]))
ans=0
for i in range(1,n+1):
    if(h[i-1]>=pre[i]):
        ans+=1
print(ans)
