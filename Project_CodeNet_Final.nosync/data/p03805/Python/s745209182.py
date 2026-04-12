import itertools
def course_judge(edge,arr):
    ok = True
    for i in range(1,len(arr)):
        go = arr[i-1]
        to = arr[i]
        if edge[go][to] == 0 or edge[to][go] == 0:
            ok = False
    return ok

N,M = map(int,input().split())
arr = [i for i in range(1,N+1)]
edge = [[0]*(N+1) for i in range(N+1)]
for i in range(M):
    go,to = map(int,input().split())
    edge[go][to] = 1
    edge[to][go] = 1
count = 0
for a in itertools.permutations(arr):
    if a[0] == 1 and course_judge(edge,a):
        count += 1
print(count)