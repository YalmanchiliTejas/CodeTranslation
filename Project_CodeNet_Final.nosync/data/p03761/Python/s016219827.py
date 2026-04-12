n = int(input())
S = [input() for _ in range(n)]
alp = [[0]*n for _ in range(26)]
OFS = ord('a') # 97

for i, s in enumerate(S):
  for x in s:
    alp[ord(x)-OFS][i] += 1
    

ans = ''
for i, a in enumerate(alp):
  ans += chr(i+OFS)*min(a)

print(ans)