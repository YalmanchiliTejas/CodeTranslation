import sys

N,K = map(int, input().split())
res = 0
if K==0:
    print(N*N)
    sys.exit(0)
for i in range(N):
    i += 1
    if i-K<=0:
        continue
    amari = N % i
    amari = amari - K + 1
    re = N // i
    if amari <= 0:
        amari = 0
    res += re*(i-K) + amari
print(res)