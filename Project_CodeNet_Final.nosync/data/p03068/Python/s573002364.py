N = int(input())
S = list(input())
K = int(input())
 
st = S[K-1]

for i in range(len(S)):
    if S[i] != st:
        S[i] = "*"

print(''.join(S))