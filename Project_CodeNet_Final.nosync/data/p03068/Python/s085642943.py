N=int(input())
S=input()
K=int(input())
ans=[0 for i in range(N)]
d=S[K-1]
for i in range(N):
    if S[i] == d:
        ans[i]=S[i]
    else:
        ans[i]='*'
print(''.join(ans))