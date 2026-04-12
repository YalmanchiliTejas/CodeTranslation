n = int(input())
a = list(map(int,input().split()))
al = []
g = []
k = []
g0 = 0
k0 = 0
for i in range(n):
    if i % 2 == 0:
        k0 += a[i]
        k.append(k0)
    else:
        g0 += a[i]
        g.append(g0)
if n % 2 == 0:
    al.append(g[n//2-1])
    al.append(k[n//2-1])
    for i in range(n):
        if i % 2 == 0 and i < n-2:
            now = i//2
            al.append(k[now]+g[-1]-g[now])
else:
    #print(g,k)
    al.append(g[-1])
    d = a[1]
    for i in range(n):
        if i % 2 == 0:
            al.append(k[-1]-a[i])
        else:
            now = (i-1)//2
            if i > 1 and i < n-2:
                #print(d,g[-1]-g[now],k[-1]-k[now+1],g[now-1],k[now-1],a[i])
                al.append(max(g[-1]-g[now],k[-1]-k[now+1])+max(d,k[now-1])+a[i])
                d = max(d+a[i],k[now-1]+a[i])
            elif i == 1:
                al.append(a[i]+max(g[-1]-g[now],k[-1]-k[now+1]))
                d = max(a[i],a[0])
            else:
                al.append(a[i] + max(d,k[now-1]))
#print(al)
print(max(al))