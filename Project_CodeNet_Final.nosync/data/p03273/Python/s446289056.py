h,w=map(int,input().split())
a=[input() for i in range(h)]
b=[]
c=[]
ans=[]
for i in range(h):
    if "#" in a[i]:
        b.append(a[i])
c=list(zip(*b))
for j in range(w):
    if "#" in c[j]:
        ans.append(c[j])
ans=list(zip(*ans))
for k in range(len(ans)):
    print(*ans[k],sep='')