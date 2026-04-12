from collections import Counter
from functools import reduce
print(''.join(sorted(reduce(lambda a,b:a&b,[Counter(input())for _ in[0]*int(input())]).elements())))