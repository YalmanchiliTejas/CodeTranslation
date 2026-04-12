n = int(input())
lst = [int(x) for x in input().split()]

count = 1
for i in range(1,n):
  if(max(lst[0:i])<=lst[i]):
    count+=1
print(count)