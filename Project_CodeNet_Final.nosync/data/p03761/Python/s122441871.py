N = int(input())
SS = [list(input()) for _ in range(N)]

CNT = [60] * 26

for S in SS:
  c = [0] * 26
  for s in S:
    c[ord(s)-97] += 1
  
  for i in range(26):
    CNT[i] = min(CNT[i],c[i])
    
ANS = ""
for i in range(26):
  s = chr(97+i)
  ANS += s * CNT[i]
  
print(ANS)
