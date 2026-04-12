from collections import Counter
n = int(input())
inp =  list(input())
d = dict(Counter(inp))

for _ in range(n-1):
  inp =  list(input())
  dic = dict(Counter(inp))
  for st,cnt in dic.items():
    try:
      if d[st] > cnt:
        d[st] = cnt
    except KeyError:
      continue
     
  remove = []
  for k in d.keys():
    if not k in dic:
      remove.append(k)
      
  for r in remove:
    d.pop(r)
      
sort_d = sorted(d.items(),key=lambda x : x[0])
#print(sort_d)

ans = ""
for so in sort_d:
  ans += so[0]*so[1]
print(ans)

