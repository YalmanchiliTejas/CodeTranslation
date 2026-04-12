import numpy
h,w = map(int, input().split())
l = list()
for i in range(h):
    l.append(list(input()))
l = numpy.array(l)
kari = 0
kari2 = []
for i in range(h):
    for j in range(w):
        if l[i][j] == ".":
            kari += 1
    if kari == w:
        kari2.append(i)
    kari = 0
kari2 = kari2[::-1]
h -= len(kari2)
for i in kari2:
    l = numpy.delete(l, i, 0)
kari2 = []
for i in range(w):
    for j in range(h):
        if l[j][i] == ".":
            kari += 1
    if kari == h:
        kari2.append(i)
    kari = 0
kari2 = kari2[::-1]
for i in kari2:
    l = numpy.delete(l, i, 1)
l = l.tolist()
for i in range(h):
    print(*l[i],sep="")
