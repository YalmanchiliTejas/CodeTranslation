N = int(input())
S = input()
K = int(input())-1

target = S[K]
for i in S:
    if i != target:
        print('*', end='')
    else:
        print(i, end='')