import numpy
h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
a = numpy.asarray(a)
a = a[:, numpy.any(a == "#", axis=0)]
a = a[numpy.any(a == "#", axis=1)]
for i in range(len(a)):
    print("".join(a[i]))
