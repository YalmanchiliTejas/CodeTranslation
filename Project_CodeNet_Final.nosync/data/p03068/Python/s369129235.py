N = int(input())
S = list(input())
K = int(input())

ok_str = S[K-1]

for i in range(N):
    if S[i] == ok_str:
        pass
    else:
        S[i] = '*' 

print(''.join(S))