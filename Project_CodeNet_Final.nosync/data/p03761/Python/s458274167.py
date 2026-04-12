n = int(input())
list_1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
dic = {}
for al in list_1:
  dic[al] = 100
for i in range(n):
  s = input()
  for al in list_1:
    count = 0
    for t in s:
      if al == t:
        count += 1
    if dic[al] > count:
      dic[al] = count
ans = ''
for al in list_1:
  if dic[al] > 0:
    for i in range(dic[al]):
      ans += al
print(ans)
