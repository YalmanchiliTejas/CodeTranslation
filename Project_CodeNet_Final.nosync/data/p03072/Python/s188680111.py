N = int(input())
H = list(map(int,input().split()))
count = 0
tmp2 = 0
for i in range(N):
  tmp = H.pop(0)
  if(i == 0):
    count += 1
    tmp2 = tmp
  else:
    if(tmp2 <= tmp):
      count += 1
      tmp2 = tmp
print(str(count))