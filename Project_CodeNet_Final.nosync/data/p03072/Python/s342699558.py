a = 0
list1 = []
for i in range(2):
  if i == 0:
    a = list(map(int,input().split()))[0]
  if i == 1:
    list1 = list(map(int,input().split()))
    
max = list1[0]
sum = 0
for i in list1:
  if (i >= max):
    sum += 1
    max = i
print(sum)
  