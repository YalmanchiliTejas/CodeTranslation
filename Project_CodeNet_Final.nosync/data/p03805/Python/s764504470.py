import itertools
n,m = map(int,input().split())
e = [list(map(int,input().split())) for _ in range(m)]

seq = tuple([x for x in range(2,n+1)])
route = list(itertools.permutations(seq))

ans = 0
for t in route:
    now = 1
    flag = True
    t = list(t)
    for i in t:
        (p,q) = (now,i) if now < i else (i,now)
        if [p,q] not in e:
            flag = False
            break
        now = i
    if flag:
        ans += 1

print(ans)