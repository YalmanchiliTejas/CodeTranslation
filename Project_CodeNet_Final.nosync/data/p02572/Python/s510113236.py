import sys
import itertools
tokens = itertools.chain.from_iterable(map(str.split, sys.stdin))

mod = 1000000007
n = int(next(tokens))
a = [int(next(tokens)) % mod for _ in range(n)]

sms = []
sma = sum(a)
for i in range(n):
    sma -= a[i]
    sms.append(sma)
#print(sms)

m = 0
for i in range(n - 1):
    sm = sms[i]
    #print(i, a[i], sm)
    m = (m + a[i] * sm) % mod

print(m)
