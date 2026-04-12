data = int(input())
list1 = list(map(int,input().split()))
s = 0
for i in range(data-1):
  if list1[i+1] >= max(list1[:i+1]): 
    s = s + 1
  else:
    None
print(s+1)