N=int(input())
S=input()
K=int(input())

c=S[K-1]

ans=[]

for s in S:
    if s==c:
        ans.append(c)
    else:
        ans.append('*')
    
print(''.join(ans))