n = int(input())
al = list(map(int, input().split())) 

p = 10**9+7

sal = sum(al)  % p

import itertools
cumsum = list(itertools.accumulate(al))

temp = 0

for i in range(n):
    temp += (sal-cumsum[i]) *al[i]
    temp = temp % p

print(temp)