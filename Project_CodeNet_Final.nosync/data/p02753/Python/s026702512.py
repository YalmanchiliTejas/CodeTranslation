import sys
from collections import Counter

sys.setrecursionlimit(1000000)
input = lambda: sys.stdin.readline().rstrip()

S = input()
print('Yes' if len(Counter(S).keys()) == 2 else 'No')


