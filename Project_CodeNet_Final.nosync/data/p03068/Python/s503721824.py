N = int(input())
S = input()
K = int(input())

s = ''
for i in range(N):
    if S[i] == S[K-1]:
        s += S[i]
    else:
        s += '*'

print(s)