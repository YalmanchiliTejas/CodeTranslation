N = int(input())
S = input()
K = int(input()) - 1
for i in range(N):
    if S[i] == S[K]:
        print(S[K], end='')
    else:
        print('*', end='')