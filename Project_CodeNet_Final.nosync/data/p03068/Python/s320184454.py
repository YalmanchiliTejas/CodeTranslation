n = int(input())
s = input().strip()
k = int(input())

for _s in s:
  if _s != s[k-1]:
    print('*', end='')
  else:
    print(_s, end='')
print()