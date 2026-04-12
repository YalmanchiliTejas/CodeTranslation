# coding:utf-8

INF = float('inf')


def inpl(): return list(map(int, input().split()))


h, w = inpl()
A = []
for i in range(h):
    a = list(input())
    A.append(a)

comp = []
for i in range(h):
    for j in range(w):
        if A[i][j] == '#':
            comp.append([1 for _ in range(w)])
            break
    else:
        comp.append([0 for _ in range(w)])

B = list(zip(*A))[:]
comp = list(zip(*comp))[:]
for i in range(w):
    for j in range(h):
        if B[i][j] == '#':
            # comp[i] = list(comp[i])
            break
    else:
        comp[i] = [0 for _ in range(h)]

comp = list(zip(*comp))[:]


ans = []
for i in range(h):
    tmp = []
    for j in range(w):
        if comp[i][j] == 1: tmp.append(A[i][j])
    if tmp != []:
        ans.append(tmp)


for i in range(len(ans)):
    print(''.join(ans[i]))