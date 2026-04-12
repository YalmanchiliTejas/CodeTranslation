# -*- coding: utf-8 -*-

line = input().split()
h = int(line[0])
w = int(line[1])

a = []
hr = []
for hi in range(h):
    line = list(input())
    if len(set(line))==1 and line[0]==".":
        hr.append(hi)
    a.append(line)


wr = []
wi = 0
for line in zip(*a):
    if len(set(line))==1 and line[0]==".":
        wr.append(wi)
    wi += 1

for hi in range(h):
    if hi in hr:
        continue
    for wi in range(w):
        if wi not in wr:
            print(a[hi][wi], end="")
    print("")
