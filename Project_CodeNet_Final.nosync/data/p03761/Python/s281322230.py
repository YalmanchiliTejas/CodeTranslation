from collections import Counter, defaultdict
from string import ascii_lowercase
INF = 1<<60
N = int(input())
alph_A = [INF]*26
for _ in range(N):
  S = input()
  for i, s in enumerate(ascii_lowercase):
    alph_A[i] = min(alph_A[i], S.count(s))
    
ans = ""    
for i, s in enumerate(ascii_lowercase):
  ans += s*alph_A[i]
print(ans)  
    
  
  