n=int(input())
al=list('abcdefghijklmnopqrstuvwxyz')
d=[[0]*n for i in range(26)]
for i in range(n):
    s=list(input())
    for j in s:
        d[al.index(j)][i]+=1
ans=''
for i in range(26):
    m=min(d[i])
    for j in range(m):
        ans+=al[i]
print(ans)