n = int(input())
s = input()
k = int(input())

x = s[k-1]
for i in range(n):
  if s[i] == x:
    print(x, end='')
  else:
    print('*', end='')