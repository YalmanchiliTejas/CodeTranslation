import math
import string


def readints():
    return list(map(int, input().split()))


def nCr(n, r):
    return math.factorial(n)//math.factorial(n-r)*math.factorial(r)


n = int(input())
w = list(map(int, input().split()))
cnt = 0
for i in range(n):
    a = True
    for j in range(i):
        if w[j] > w[i]:
            a = False
            break
    if a:
        cnt += 1
print(cnt)
