import re

N = int(input())
S = input()
K = int(input())

ans = re.sub(r"[^{}]".format(S[K-1]), "*", S)
print(ans)
