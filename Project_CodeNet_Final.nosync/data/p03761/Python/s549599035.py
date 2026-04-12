n = int(input())
s = input()
d = dict()

for i in s:
    if i in d.keys():
        d[i] += 1
    else:
        d[i] = 1

for j in range(n-1):
    s = input()
    d2 = dict()
    for i in s:
        if i in d.keys():
            if i in d2.keys():
                d2[i] += 1
            else:
                d2[i] = 1
    for k in d.keys():
        if not k in d2.keys():
           d[k] = 0
        else:
            if d[k] > d2[k]:
                d[k] = d2[k]

for k in sorted(d.keys()):
    for l in range(d[k]):
        print(k, end='')

print()
