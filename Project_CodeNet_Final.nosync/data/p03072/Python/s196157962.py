num = int(input())
list = [int(i) for i in input().split()]
sum = 0
for j in range(num):
  list1 = list[:j+1]
  #print(list1)
  #print(max(list1))
  #print(list1[-1])
  if max(list1) == list1[-1]:
    sum += 1
  else:
    pass
print(sum)