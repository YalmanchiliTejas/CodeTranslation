n,m=map(int,input().split())
s=[[]for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    s[a-1].append(b-1)
    s[b-1].append(a-1)
c=0
k=[]
p=[[0]]
for i in range(m):
    k=[]
    for j in range(len(p[:])):
        for h in range(len(s[p[j][-1]])):
            t=s[p[j][-1]]
            if not t[h] in p[j]:
                k.append(p[j]+[t[h]])
                if len(k[-1])==n:
                    c+=1
                    k.pop(-1)
    else:
        p=k[:]
print(c)