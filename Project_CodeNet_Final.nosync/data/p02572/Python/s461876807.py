import itertools
N = int(input())
a = list(map(int,input().split()))
a2 = itertools.accumulate(a)
b = [0]
b += list(a2)
s = 0
for i in range(N):
    s += (a[i] * (b[-1] - b[i+1]))
print(s % (10**9+7))