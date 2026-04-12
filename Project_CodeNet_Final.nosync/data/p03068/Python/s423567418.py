import re

N=int(input())
S=input()
K=int(input())

pat = re.compile(r'[^{0}]'.format(S[K-1]))

print(re.sub(pat,'*',S))