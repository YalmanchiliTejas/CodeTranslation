N = int(input())
S = input()
K = int(input())

s_k = S[K-1]

s = ''
for i in range(len(S)):
    if S[i] != s_k:
        s += '*'
    else:
        s += S[i]

print(s)
