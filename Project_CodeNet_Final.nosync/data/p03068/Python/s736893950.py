import re
input()
S=raw_input()
K=input()
a=[]
for i in range(len(S)):
  k=map(lambda x:x.start(),re.finditer(S[K-1],S))
  if i in k:
      a.append(S[i])
  else:
      a.append("*")
print(''.join(a))
