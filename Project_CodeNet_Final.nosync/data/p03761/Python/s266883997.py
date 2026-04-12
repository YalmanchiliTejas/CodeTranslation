N=int(input())
import string
S=[]
d = dict.fromkeys(string.ascii_lowercase, 0)
for i in range(N):
  dc = d.copy()
  k = input()
  for s in k:
    dc[s] += 1
  S.append(dc)
ANS = ''

for s in string.ascii_lowercase:
  m = 50
  for i in range(N):
    m = min(m, S[i][s])
  ANS += (s * m)
    
print(ANS)
  
  