N = int(input())
S = input()
K = int(input())

a = S[K-1]
for i in S:
    if i != a:
        print('*',end='')
    else:
        print(i,end='')