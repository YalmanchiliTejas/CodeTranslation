input()
S = input()
K = int(input())

c = S[K -1]
for i in S:
    if i != c:
        print('*', end='')
    else:
        print(i, end='')
