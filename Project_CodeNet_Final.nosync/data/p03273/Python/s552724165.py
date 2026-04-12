import math


def readints():
    return list(map(int, input().split()))


def nCr(n, r):
    return math.factorial(n)//math.factorial(n-r)*math.factorial(r)


h, w = map(int, input().split())
a = [None]*h
# print(a)
for i in range(h):
    a[i] = input()
# print(a)
x = [None]*h
y = [None]*w
# print(x)
# print(y)
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            x[i] = True
            y[j] = True
# print(x)
# print(y)
for i in range(h):
    if x[i] == True:
        for j in range(w):
            if y[j] == True:
                print(a[i][j], end="")
        print()
