N = int(input())
S = [i for i in input()]
K = int(input())

point = S[K-1]
for i in range(N):
    if(S[i]!=point):
        S[i] = '*'
print(''.join(S))