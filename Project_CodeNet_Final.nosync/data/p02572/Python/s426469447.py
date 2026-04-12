N = int(input())
l = list(map(int, input().split()))
import itertools

total = sum(l)
cumsum = list(itertools.accumulate(l))

i = 0
sig = 0
for cus in cumsum:
    rest = (total - cus)
    
    sig += (l[i] * rest)
    i +=1
    
    
print(sig % (10**9 + 7))