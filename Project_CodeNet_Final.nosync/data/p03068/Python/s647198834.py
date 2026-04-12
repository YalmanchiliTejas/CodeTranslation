N = int(input())
S = input()
K = int(input())
A = S[K-1]
for s in S:
    if s != A:
        S = S.replace(s,'*')
print(S)