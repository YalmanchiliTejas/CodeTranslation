N = int(input())
List = list(map(int, input().split()))
res = 0
flag = True
for i in range(N):
  for j in range(0,i):
    if List[j] > List[i]:
      flag = False
  if flag:
    res += 1
  flag = True
print(res)