N = int(input())
S = str(input())
K = int(input())

s = S[K-1]
star = '*'
sout = ''
for i in range(N):
   if S[i] == s:
      sout = sout + s
   else:
      sout = sout + star
print(sout)