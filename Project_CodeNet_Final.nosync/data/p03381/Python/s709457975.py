
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
##############################

N = int(input())
X = list(map(int, input().split()))

x = X[:]
x.sort()
m1 = x[N//2 - 1]
m2 = x[N//2]

for a in X:
    if a <= m1:
        print(m2)
    else:
        print(m1)