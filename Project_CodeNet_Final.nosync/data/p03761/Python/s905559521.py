n = int(input())
l = list(input())
m = []

for i in range(n - 1):
    ref = list(input())
    for j in ref:
        if j in l:
            m.append(j)
            l.remove(j)
    l = m
    m = []
l.sort()

print("".join(l))