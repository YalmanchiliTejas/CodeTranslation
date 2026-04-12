n = int(input())
s_list = [list(input()) for nesya in range(n)]
a = [50]*26
for s in s_list:
  ho = [0]*26
  for l in s:
    k = ord(l) - ord('a')
    ho[k] += 1
  for i in range(26):
    if a[i] > ho[i]:
      a[i] = ho[i]
for j in range(26):
  if a[j] == 0:
    pass
  else:
    b = chr(j+ord('a'))
    print(b*a[j],end='')
print()