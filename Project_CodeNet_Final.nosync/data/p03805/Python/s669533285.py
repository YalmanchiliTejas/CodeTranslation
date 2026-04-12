import itertools
n,m = map(int,input().split())
ways = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    ways[a-1].append(b-1)
    ways[b-1].append(a-1)
checklist = [0]*n
position = 0 #first position
cnt = 0
if n == 2:
    if 1 in ways[0]:
        print(1)
    else:
        print(0)
    exit()
for p in itertools.permutations(range(1,n)):
    if p[0] in ways[0]:
        flag = True
        for i in range(n-2):
            if p[i+1] not in ways[p[i]]:
                flag = False
                break
        if flag:
            cnt += 1
print(cnt)
