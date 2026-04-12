n,m=map(int,input().split())
l=list(range(2,n+1))
v=[[] for i in range(1+n)]
for i in range(m):
    a,b=map(int,input().split())
    v[a].append(b)
    v[b].append(a)

def check(ls):
    fr=1
    for to in ls:
        if int(to) not in v[fr]:
            return 0
        fr=int(to)
    return 1

def gen(ls):
    if not ls:
        return [[]]
    return [[a]+b for i,a in enumerate(ls) for b in gen(ls[:i]+ls[i+1:])]
    
print(sum([check(i) for i in gen(l)]))