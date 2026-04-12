import sys
input = sys.stdin.readline
from collections import Counter
import string

n = int(input())
s = Counter(input().rstrip("\r\n"))
for _ in range(n-1):
    s &= Counter(input().rstrip("\r\n"))
print("".join(sorted(s.elements())))