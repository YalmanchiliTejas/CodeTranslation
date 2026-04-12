from collections import Counter
from functools import reduce
n = int(input())
print(''.join(sorted(reduce(lambda a,b:a&b, [Counter(input()) for a in range(n)]).elements())))