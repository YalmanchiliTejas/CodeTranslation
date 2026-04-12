import math
 
h,w = list(map(int, input().split()))
data = []
for i in range(h):
    a=list(map(str, input().split()))
    data.append(a[0])

hlist=[]
wlist=[]
for i in range(h):
    flag=0
    for j in range(w):
        if(data[i][j]=='#'):
            flag=1
    if(flag==1):
        hlist.append(i)

for i in range(w):
    flag=0
    for j in range(h):
        if(data[j][i]=='#'):
            flag=1
    if(flag==1):
        wlist.append(i)
        

for i in range(len(hlist)):
    temp=""
    for j in range(len(wlist)):
        temp+=data[hlist[i]][wlist[j]]
    print(temp)