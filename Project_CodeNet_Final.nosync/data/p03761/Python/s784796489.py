from collections import Counter
from functools import reduce

def f(lst1,lst2):
    return lst1&lst2

n = int(input())
S = [Counter(input()) for _ in range(n)]
T = list((reduce(f,S)).elements())
T.sort()
ans = ''.join(T)
print(ans)