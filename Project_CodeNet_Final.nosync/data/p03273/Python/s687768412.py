H, W = map(int, input().split())
A = []

for _ in range(H):
    a = input()
    A.append(a)

result = []
temp = []

for a in A:
    flag = True
    for s in a:
        if s != '.':
            flag = False
            break
    if not flag:
        temp.append(a)

idx = []

for i in range(W):
    flag = True
    for s in temp:
        if s[i] != '.':
            flag = False
            break
    if not flag:
        idx.append(i)

for s in temp:
    t = ''
    for i in idx:
        t += s[i]
    result.append(t)

print(*result, sep='\n')


