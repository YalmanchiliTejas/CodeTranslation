a,b=map(int,input().split())
l=[]
for i in range(a):
    s=input()
    if set(s)=={"."}:
        continue
    else:
        l.append(s)
#print(l)
r=""
l2=[]
for i in range(b):
    for t in range(len(l)):
        r+=l[t][i]
#    print(r)
    if set(r)!={"."}:
        l2.append(r)
    r=""
g=""
#print(l2)
for i in range(len(l2[0])):
    for t in l2:
        g+=t[i]
    print(g)
    g=""
        