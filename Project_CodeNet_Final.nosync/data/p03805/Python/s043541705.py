n,m=map(int,input().split())
e=[[] for _ in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    e[a].append(b)
    e[b].append(a)

fp=set()
def rec(cur):
    ret = 0
    fp.add(cur)
    if len(fp) == n:
        fp.remove(cur)
        return 1
    for nex in e[cur]:
        if nex not in fp:
            ret += rec(nex)
    fp.remove(cur)
    return ret
print(rec(0))