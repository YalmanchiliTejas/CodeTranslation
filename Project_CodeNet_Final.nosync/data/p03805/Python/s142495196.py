import copy
A = list()
n, m = map(int, input().split())
for i in range(m):
    a = list(map(int, input().split()))
    A.append(a)
    A.append([a[1], a[0]])

B = list()

def update(current=[1], rest=A, count = 0):
    next = list(filter(lambda x: x[0] == current[count], rest))
    if len(current) < n:
        for ne in next:
            l = copy.deepcopy(current)
            l.append(ne[1])
            nRest = list(filter(lambda x: x[0] != current[count] and x[1] != current[count] and x[1] != ne[1], rest))
            update(l, nRest, count + 1)
    else:
        B.append(current)

update()
print(len(B))