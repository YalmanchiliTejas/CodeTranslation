import numpy as np
import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
from collections import defaultdict

N, *A = map(int, read().split())

INF = 10**18
dp_not = defaultdict(lambda : -INF)
dp_take = defaultdict(lambda: -INF)
dp_not[(0,0)] = 0

for i,x in enumerate(A,1):
	j = (i-1)//2
	for n in (j,j+1):
		dp_not[(i,n)] = max(dp_not[(i-1,n)], dp_take[(i-1,n)])
		dp_take[(i,n)] = dp_not[(i-1,n-1)] + x

print(max(dp_not[(N, N//2)], dp_take[(N, N//2)]))