import re
N = input()
S = input().strip()
K = int(input())
print(re.sub("[^" + str(S[K - 1]) + "]", "*", S))