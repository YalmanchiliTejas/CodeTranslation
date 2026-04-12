import statistics
from bisect import bisect_left
N = int(input())
X = list(map(int,input().split()))
Y = sorted(X)
a,b = statistics.median_low(Y),statistics.median_high(Y)
for i in X:
    Z = bisect_left(Y,i)
    if Z<N//2:
        print(b)
    else:
        print(a)