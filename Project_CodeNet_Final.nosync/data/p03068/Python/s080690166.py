N=int(input())
S=input()
K=int(input())
a=S[K-1]
for i in range(N):
    if a==S[i]:
        print(a,end='')
    else:
        print('*',end='')

