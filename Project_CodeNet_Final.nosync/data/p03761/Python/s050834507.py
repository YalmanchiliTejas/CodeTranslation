from collections import Counter
n = int(input())
s = []
s0 = list(input())
sc = Counter(s0)
for i in range(1,n):
    a = list(input())
    ac = Counter(a)
    for i,v in ac.items():
        if i not in sc:
            continue
        elif sc[i] > v:
            sc[i] = ac[i]
    for i,v in sc.items():
        if i not in ac:
            sc[i] = 0
sc2 = sorted(sc.items())
for i,v in sc2:
    for j in range(v):
        print(i,end='')
            