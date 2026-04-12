N = int(input())
S = list(input())
K = int(input())

for i in range(N):
    if S[i] == S[K-1]:
       pass
    else:
       S[i] = '*'
        
        
mojiretu = ','.join(S)
print(mojiretu.replace(',', ''))

