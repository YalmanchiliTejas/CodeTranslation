def mycounter(dd,l):
    d=dict()
    for i in l:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    ddd=dict()
    for i in d.keys():
        if i in dd:
            ddd[i]=min(d[i],dd[i])
    return ddd

n=int(input())
d=dict()
for i in input():
    if i in d:
        d[i]+=1
    else:
        d[i]=1
for i in range(n-1):
    d=mycounter(d,input())
p=""
for i,j in sorted(d.items()):
    p+=i*j
print(p)