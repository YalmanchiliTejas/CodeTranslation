N = int(input())
S = input()
K = int(input())

s = S[K-1]

txt = ''

for i in range(N):
    if S[i] == s:
        txt += s
    else:
        txt += '*'

print(txt)