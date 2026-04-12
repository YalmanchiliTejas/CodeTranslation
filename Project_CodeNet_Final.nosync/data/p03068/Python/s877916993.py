N=int(input())
S=input()
K=int(input())
c=S[K-1]
for i in range(N):
    if S[i]==c:
        print(c,end='')
    else:
        print('*',end='')