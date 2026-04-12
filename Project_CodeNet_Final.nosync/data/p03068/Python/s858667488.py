N = int(input())
S = input()
K = int(input()) - 1
tx = S[K]
s = []
for i in range(N):
    if S[i] != tx:
        s.append('*')
    else:
        s.append(S[i])
print(''.join(s))