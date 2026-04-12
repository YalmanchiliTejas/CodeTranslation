n = int(input())
a = input()
l = int(input())
for i in range(n):
  if a[l-1] != a[i]:
    print('*', end='')
  else:
    print(a[l-1], end='')