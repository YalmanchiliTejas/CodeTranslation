from sys import exit
def Fi():
    print('First')
    exit()

N = int(input())
dim = [-1]*N
Edge = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    dim[a-1] += 1
    dim[b-1] += 1
    Edge[a-1].append(b-1)
    Edge[b-1].append(a-1)
par = [None] + [0]*(N-1)
stack = [0]
visited = set([0])
while stack:
    vn = stack.pop()
    for vf in Edge[vn]:
        if vf in visited:
            continue
        visited.add(vf)
        par[vf] = vn
        stack.append(vf)

L = [i for i in range(1,N) if dim[i] == 0]
used = set(L)
stack = L[:]
mat = [0]*N
dim[0] += 2
while stack:
    vn = stack.pop()
    pv = par[vn]
    if pv is None:
        break
    if mat[vn] == 0:
        mat[vn] += 1
        mat[pv] += 1
    dim[pv] -= 1
    if dim[pv] == 0:
        stack.append(pv)
print('Second' if all(m == 1 for m in mat) else 'First')