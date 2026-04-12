n, m = map(int, input().split())
s = []
a = []
for _ in range(n):
    x = input()
    if '#' in x:
        s.append(x)
for j in range(m):
    res = False
    for x in s:
        if x[j] == '#':
            res = True
            break
    a.append(res)
s = ["".join(x[i] for i in range(m) if a[i]) for x in s]

for x in s:
    print(x)