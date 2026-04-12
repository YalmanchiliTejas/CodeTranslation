N=int(input())
S=list(input())
K=int(input())

ans = []
a = S[K-1]

for i in range(N):
    if S[i] == S[K-1]:
       ans.append(a)
    else:
       ans.append('*')

mojiretu = ' '

for x in ans:
    mojiretu += x
    
print(mojiretu)
    