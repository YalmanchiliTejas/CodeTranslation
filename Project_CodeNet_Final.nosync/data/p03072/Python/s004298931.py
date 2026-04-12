n = int(input())
h_list = [int(i) for i in input().split()]

count = 1
for i in range(1, n):
  flag = True
  for j in range(i):
    if h_list[j] > h_list[i]:
      flag = False
      break
  if flag:
    count +=1

print(count)