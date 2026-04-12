import sys
input = sys.stdin.readline

S = input().rstrip()
from collections import Counter

c = Counter(S)

if len(c.keys()) == 2:
    print("Yes")
else:
    print("No")