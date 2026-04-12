a, b = map(int, input().split())
L = []
for i in range(a):
    l = input()
    if not l.count('.') == b:
        L.append(l)

M = []
for i in range(b):
    l = list(map(lambda x: x[i], L))
    if not l.count('.') == len(l):
        M.append(l)

for i in range(len(M[0])):
    for m in M:
        print(m[i],end='')
    print()