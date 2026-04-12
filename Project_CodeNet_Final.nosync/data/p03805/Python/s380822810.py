n,m=map(int,input().split())
path=[list(map(int,input().split())) for i in range(m)]
# print(path)

def ok(l1, now, next):
    # print([l1])
    # print([now, next])
    l=l1[:]
    count=0
    if [now,next] in path or [next, now] in path:
        l.remove(next)
        if len(l)==0:
            return 1
        for i in range(len(l)):
            count+=ok(l, next, l[i])
        return count
    else:
        return 0

li=[i+1 for i in range(1,n)]

now=1
tmp=li[:]
count=0
for i in range(len(tmp)):
    count+=ok(tmp, now, tmp[i])
print(count)