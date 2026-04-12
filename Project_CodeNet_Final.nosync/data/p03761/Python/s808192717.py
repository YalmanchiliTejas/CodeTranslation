n = int(input())
count = {}
S1 = list(input())
for s in S1:
  if s in count.keys():
    count[s] += 1
  else:
    count[s] = 1
for i in range(n-1):
  S = list(input())
  count1 = {}
  for s in S:
    if s in count1.keys():
      count1[s] += 1
    else:
      count1[s] = 1
  for k,v in count.items():
    if k in count1.keys():
      count[k] = min(v,count1[k])
    else:
      count[k] = 0
items = sorted(count.items())
ans = ""
for i in range(len(items)):
  ans += items[i][0]*items[i][1]
print(ans)