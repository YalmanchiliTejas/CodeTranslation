N = int(input())
S = input()
K = int(input())
s = []
for i in range(N):
    if S[i] == S[K-1]:
        s.append(S[i])
    else:
        s.append('*')

for i in range(N):
    print(s[i], end = '')

print()