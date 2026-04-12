N = int(input())
S = str(input())
K = int(input())
x = S[K-1]
for i in S:
    if i == x:
        print(i, end='')
    else:
        print('*', end='')
print('')