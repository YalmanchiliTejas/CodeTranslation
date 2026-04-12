import numpy
h, w = map(int, input().split())
ls = [list(input()) for _ in range(h)]
ls = numpy.array(ls)
ls = ls[numpy.any(ls == "#", axis=1), :]
ls = ls[:, numpy.any(ls == "#", axis=0)]
for i in list(ls):
    print("".join(i))
