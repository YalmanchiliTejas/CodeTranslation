from collections import defaultdict
n = int(input())
lis = []
dd = defaultdict(int)
for i in range(n):
  s = input() 
  
  lis.append(s)
  if i==0:
    for j in range(len(s)):
      dd[s[j]]+=1
  else:
    tmp = defaultdict(int)
    for j in range(len(s)):
      tmp[s[j]]+=1 
    for key in dd.keys():
      if dd[key]!=0 and tmp[key]!=0:
        dd[key] = min(dd[key], tmp[key])
      else:
        dd[key]=0
        

res = []
for key in dd.keys():
  if dd[key]!=0:
    res.append(key*dd[key])
res.sort()
print(''.join(res))

