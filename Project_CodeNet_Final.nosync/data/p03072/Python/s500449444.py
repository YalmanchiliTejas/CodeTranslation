N = input()
N = int(N)
str = input().split()
H = []
i = 0
j = 0
for i in range(N):
  H.append( int(str[i]) )
flag = 0
ans = 0
for i in range(N):
  for j in range(i):
    if H [i] < H[j]:
      flag =  1
      break
    else:
      flag = 0
  if flag == 0:
    ans = ans+1
  flag = 0

print(ans)