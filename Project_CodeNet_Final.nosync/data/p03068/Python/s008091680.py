N=int(input())
S=list(input())
K=int(input())
moji=S[K-1]
#print(moji)

for i in range(N):
    
    if S[i]!=moji:
        S[i]="*"
mojiretu=""
for x in S:
  mojiretu+=x
print(mojiretu)