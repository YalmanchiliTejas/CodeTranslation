from collections import Counter
from functools import reduce 
n=int(input())
if n == 1: 
    print(''.join((sorted(input()))))
else:
    print(''.join(sorted(list(reduce(lambda a,b: Counter(a) & Counter(b), [sorted(input()) for i in range(n)]).elements()))))
