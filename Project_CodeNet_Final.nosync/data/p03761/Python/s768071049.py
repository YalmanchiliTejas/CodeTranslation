N = int(input())

dic = {}
s = str(input())
for i in range(len(s)):
  if s[i] not in dic:
    dic[s[i]] = 1
  else:
    dic[s[i]] += 1

K = list(dic.keys())
K.sort()
for i in range(1,N):
  temp = str(input())
  for j in range(len(K)):
    if K[j] not in temp:
      dic[K[j]] = 0
      continue
    if temp.count(K[j]) < dic[K[j]]:
      dic[K[j]] = temp.count(K[j])

ans = ""
for i in range(len(K)):
  while dic[K[i]] > 0:
    ans += K[i]
    dic[K[i]] -= 1
print(ans)