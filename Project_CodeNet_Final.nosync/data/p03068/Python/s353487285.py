N = int(input())
S = str(input())
K = int(input())
#N = 5
#S = "error"
S = list(S)
#K = 2
char = S[K-1]
for i in range(len(S)):
    if S[i] != char:
        S[i] = "*"
print(''.join(S))