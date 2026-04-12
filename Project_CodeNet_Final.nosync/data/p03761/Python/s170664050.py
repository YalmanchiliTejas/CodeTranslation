from collections import Counter

N = int(input())

dic = {chr(ord('a')+i):50 for i in range(26)}

for i in range(N):
  s = input()
  tmp = Counter(s)
  for j in range(26):
    dic[chr(ord('a')+j)] = min(dic[chr(ord('a')+j)], tmp[chr(ord('a')+j)])
    
rlt = ''
for k in dic:
  if dic[k] > 0:
    rlt += k*dic[k]
    
print(rlt)