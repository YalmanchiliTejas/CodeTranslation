N = int(input())
A = tuple(map(int,input().split()))
from collections import defaultdict
dp_non = defaultdict(lambda: -2**60)
dp_take = defaultdict(lambda: -2**60)
dp_non[(0,0)] = 0
for i,x in enumerate(A,1):
    j = (i-1)//2
    for n in (j,j+1):
        dp_non[(i,n)] = max(dp_non[(i-1,n)],dp_take[(i-1,n)])
        dp_take[(i,n)] = dp_non[(i-1,n-1)]+x
print(max(dp_non[N,N//2],dp_take[(N,N//2)]))