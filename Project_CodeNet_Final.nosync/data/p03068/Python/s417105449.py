N = int(input())
S = input()
K = int(input())
s = S[K-1]

for _ in S:
    if _ != s:
        print('*', end='')
    else:
        print(s, end='')