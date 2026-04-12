import numpy as np
n=3
a=[input() for i in range(n)]

S=list(a[1])
s=len(S)
K=int(a[2])-1

for i in range(s):
  if S[i]!=S[K]:
    S[i]="*"
mojiretu = ''
    
for x in S:
    mojiretu += x
    
print(mojiretu)