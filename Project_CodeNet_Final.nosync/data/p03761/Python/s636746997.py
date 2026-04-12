N = int(input())
dict_c = {}
for char in input():
  if char in dict_c:
    dict_c[char] += 1
  else:
    dict_c[char] = 1

for _ in range(N-1):
  word = input()
  dict_t = {}
  for char in word:
    if char in dict_t:
      dict_t[char] += 1
    else:
      dict_t[char] = 1
  for char, cnt in dict_c.items():
    if cnt != 0:
      if not char in dict_t:
        dict_c[char] = 0
      else:
        dict_c[char] = min(cnt, dict_t[char])
ans = ''
for char, cnt in sorted(dict_c.items(), key=lambda x: x[0]):
  ans += char*(cnt)
print(ans)
