h,w=map(int,input().split())
a2=[]
for i in range(h):
    a=list(input())
    if '#' in a:
        a2.append(a)
for i in range(w):
    x=[row[i] for row in a2]
    if '#' not in x:
        for j in range(len(a2)):
            a2[j][i]=''
for i in a2:
    print(*i,sep='')