import re

N = int(input())
S = input()
K = int(input())
print(re.sub(r'[^{}]'.format(S[K-1]), '*', S))
