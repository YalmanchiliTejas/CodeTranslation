from functools import reduce
from operator import add

A,B,C,X,Y  = list(map(int, input().split()))

print(min([C*i + A*max(0,X - i//2) + B*max(0,Y-i//2) for i in range(max(2*X, 2*Y)+1)]))