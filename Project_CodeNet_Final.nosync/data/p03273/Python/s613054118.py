a, b = map(int, input().split())
v = ['' for i in range(a)]
for i in range(a):
    v[i] = input()
for i in range(a):
    k = a - i - 1
    x = 0
    for j in range(b):
        if v[k][j] == '#':
            x = 1
    if x == 0:
        v.pop(k)



for i in range(b):
    k = b - i - 1
    x = 0
    for j in range(len(v)):
        if v[j][k] == '#':
            x = 1
    if x == 0:
        for j in range(len(v)):
            v[j] = v[j][:k] + v[j][k+1:]
            
for i in v:
    print(i)
