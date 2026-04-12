N = int(input())
S = str(input())
K = int(input())
S_str = S[K-1]
i = 0
for i in range(N):
    if S_str != S[i]:
        S = S.replace(S[i], "*")
        i += 1
    else:
        i += 1
print(S)
