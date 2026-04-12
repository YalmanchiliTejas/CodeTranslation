import re

N = int(input())
S = input().rstrip()
K = int(input())

r = S[K-1]
pattern = "[^%s]" % r
print(re.sub(pattern, '*', S))
