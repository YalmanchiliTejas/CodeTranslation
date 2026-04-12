N, M = map(int, input().split())
edgelist = []
for i in range(M):
    edgelist.append(set(map(int, input().split())))

s = [1]
count = 0
L = [[i for i in edgelist if (len(i&set([1]))!=0)]]
while s != []:
    if len(s) == N:
        count = count + 1
        L.pop()
        s.pop()
    elif L[-1] == []:
        L.pop()
        s.pop()
    else:
        p = L[-1].pop()
        r = list(p - set([s[-1]]))
        L.append([i for i in edgelist if (len(i&set(r))!=0)*(len(i&set(s))==0)])
        s.append(r[0])
print(count)