n = int(input())
S = str(input())
k = int(input())

S = list(S)
chr = S[k-1]
for i in range(n):
    if S[i] != chr:
        S[i] = '*'
S = ''.join(S)
print(S)
