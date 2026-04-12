N = input()
S = input()
K = input()
k = S[int(K) - 1:int(K)]
for s in S:
    if s != k:
        S = S.replace(s, '*')
print(S)
