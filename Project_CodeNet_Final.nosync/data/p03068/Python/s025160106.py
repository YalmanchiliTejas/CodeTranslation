n = int(input())
st = input().strip()
m = int(input())
d = st[m-1]
for i in range(n):
  if st[i] != d:
    print('*',end='')
  else:
    print(d, end='')