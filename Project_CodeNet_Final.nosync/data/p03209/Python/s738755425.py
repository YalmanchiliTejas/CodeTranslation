import sys
sys.setrecursionlimit(1000000000)
n, x = map(int, input().split())
b = [2**(i+2) - 3 for i in range(51)]
p = [2**(i+1) - 1 for i in range(51)]
def pate(m, k):
    if m == 0:
        return k
    else:
        if k == 0:
            return 0
        elif k <= b[m-1] + 1:
            return pate(m-1, k-1)
        elif k == b[m-1] + 2:
            return p[m-1] + 1
        elif k <= b[m] -1:
            return p[m-1] + 1 + pate(m-1, k-b[m-1]-2)
        else:
            return p[m]
print(pate(n, x))