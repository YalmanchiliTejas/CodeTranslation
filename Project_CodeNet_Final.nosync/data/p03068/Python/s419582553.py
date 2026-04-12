import re
N = int(input())
S = input()
K = int(input())

w = S[K-1]
print(re.sub("[^#]", "*", S.replace(w, "#")).replace("#", w))
