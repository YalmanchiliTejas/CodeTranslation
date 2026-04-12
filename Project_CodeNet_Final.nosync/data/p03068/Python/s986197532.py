N = int(input())
S = input()
K = int(input())

char = S[K - 1]

for c in S:
    if c == char:
        print(c, end='')
    else:
        print('*', end='')
