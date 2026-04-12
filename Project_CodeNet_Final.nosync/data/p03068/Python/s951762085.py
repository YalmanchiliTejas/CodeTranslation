n = int(input())
s = input()
k = int(input())
r = ''
for x in s:
  if x == s[k-1]:
    r += x
  else:
    r += '*'
print(r)