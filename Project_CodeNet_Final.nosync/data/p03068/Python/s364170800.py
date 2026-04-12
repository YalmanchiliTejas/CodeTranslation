import re

N = int(input())
S = input()
K = int(input())

ks = S[K-1]
print(re.sub(r"[^{}]".format(ks), "*", S))