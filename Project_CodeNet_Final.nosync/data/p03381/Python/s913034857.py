from bisect import *

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

N = read()
X = reads()
sX = sorted(X)

ml = sX[N//2 - 1]
mr = sX[N//2]

for x in X:
    print(mr if x <= ml else ml)
