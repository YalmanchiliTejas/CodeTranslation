n = int(input())
s = input()
k = int(input())

diff = s[k - 1]

lis = []

for i in range(n):
  if s[i] != diff:
    lis.append('*')
  else:
    lis.append(diff)

print(''.join(lis))