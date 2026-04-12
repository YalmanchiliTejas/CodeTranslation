n,m=map(int,input().split())

glaph={}

for i in range(1,n+1):
    glaph[i]=[]

for _ in range(m):
    a,b=map(int,input().split())
    glaph[a].append(b)
    glaph[b].append(a)

#print(glaph)

import itertools
junretsu=[]
for i in range(2,n+1):
    junretsu.append(i)
cnt=0

junretsu=list(itertools.permutations(junretsu))

#print(junretsu)
for item in junretsu:
    i=0
    flag=0
    if item[0] not in glaph[1]:
        flag=1

    while i<n-2:
        #print(item,i)
        if item[i+1] not in glaph[item[i]]:
            flag=1
        i+=1
    if flag==0:
        cnt+=1
        #print(item)
print(cnt)
