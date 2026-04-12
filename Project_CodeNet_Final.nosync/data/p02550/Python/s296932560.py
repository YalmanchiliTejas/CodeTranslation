n,x,m=map(int,input().split())
ans=x
count=1
table=[0]*m
table[x]=1
r=[0,x] #一般項
f=1
for i in range(n-1):
    x=pow(x,2,m)
    ans+=x
    count+=1
    if table[x]:
        f=0
        break
    r.append(x)
    table[x]=count
if f or table[0]:
    print(ans)
    exit()
ans=0
'''
table[x]項目とcount項目が同じ
loop前の項+loopの項*loop数+足りない分
'''
ans=sum(r[:table[x]])
loop=(n-table[x]+1)//(count-table[x])
ans+=sum(r[table[x]:])*loop
nokori=(n-table[x]+1)%(count-table[x])
for i in range(nokori):
    ans+=r[table[x]+i]
print(ans)