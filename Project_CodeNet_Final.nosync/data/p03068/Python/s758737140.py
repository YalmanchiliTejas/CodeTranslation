N = int(input())
S = list(input())
K = int(input())-1

rest_char = S[K]

for i in range(len(S)):
    if S[i] != rest_char:
        S[i] = '*'

print("".join(S))
