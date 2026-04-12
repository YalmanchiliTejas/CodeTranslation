import itertools

n,m = map(int,input().split())
graph = dict()
for i in range(1,n+1):
    graph[i] = []
for i in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

t = [i for i in range(1,n+1)]
testcase = list(itertools.permutations(t))
counter = 0
for i in range(len(testcase)):
    if testcase[i][0] != 1:
        break
    else:
        temp = True
    now = 1
    for k in range(1,n):
        if testcase[i][k] not in graph[now]:
            temp = False
            break
        else:
            now = testcase[i][k]
    if temp:
        counter += 1

print(counter)