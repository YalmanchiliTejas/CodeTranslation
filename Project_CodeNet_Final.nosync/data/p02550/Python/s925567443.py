n,x,m = map(int,input().split())
loop = []
loop.append(x)
looplist = [0]*m
looplist[x]=1
for i in range(1,m+1):
    x = x**2%m
    #print(x)
    if looplist[x]==0:
        looplist[x]=1
        loop.append(x)
    else:
        break

ss = loop.index(x)
amari = loop[:ss]
neoloop = loop[ss:]

lon = len(neoloop)

if n<=ss:
    print(sum(amari[:n]))
else:
    print(sum(amari)+(n-ss)//lon*sum(neoloop)+sum(neoloop[:(n-ss)%lon]))