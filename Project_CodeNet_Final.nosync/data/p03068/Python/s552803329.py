import re
N = int(input())
S = input()
K = int(input())

S = "".join([i if i == S[K-1] else "*" for i in S])
print(S)