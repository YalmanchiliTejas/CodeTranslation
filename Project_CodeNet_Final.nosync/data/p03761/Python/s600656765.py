N = int(input())
S = [input() for _ in range(N)]

import string 
letters=string.ascii_lowercase
dic = {}
def alpha(N,dic):
  for i in letters:
    dic[i] = [0] * N
alpha(N,dic)

for i in range(N):
  for j in range(len(S[i])):
    dic[S[i][j]][i] += 1
#print(dic)
ans = []
for i in letters:
  ans.append(i * min(dic[i]))
print(*ans,sep="")