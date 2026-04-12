from sys import stdin
n = int(stdin.readline().rstrip())
S = list(stdin.readline().rstrip())
k = int(stdin.readline().rstrip())
c = S[k-1]
for i, s in enumerate(S):
    if s != c:
        S[i]='*'
print(''.join(S))