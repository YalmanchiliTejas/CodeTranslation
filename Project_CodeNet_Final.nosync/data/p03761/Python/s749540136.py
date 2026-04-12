import collections

n = int(input())

lc = list()
ls = list()
for i in range(n):
    s = input()
    ls.append(s)
    lc.append(collections.Counter(s))

lans = list()
for i in lc[0].keys():
    lm = [lc[j][i] for j in range(n)]
    lans.append((i, min(lm)))

lans = sorted(lans)

l = list()
for i in range(len(lans)):
    l.append(lans[i][0]*lans[i][1])

print("".join(l))