N, S, K = [input() for i in range(3)]
ans = 0
S = list(S)
for n in range(int(N)):
    if S[n] != S[int(K)-1]:
        S[n] = '*'
ans = ''.join(S)
print(ans)
