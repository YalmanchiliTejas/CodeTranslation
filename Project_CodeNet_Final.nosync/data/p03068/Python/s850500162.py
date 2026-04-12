N=int(input())
S=input()
K=int(input())
tmp=[]

for i in range(N):
    if S[i] == S[K-1]:
        tmp.append(S[i])
    else:
        tmp.append('*')
print(''.join(tmp))
