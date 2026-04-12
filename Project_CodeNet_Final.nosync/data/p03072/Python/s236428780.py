n = int(input())
str_hlist = input().split(' ')

count = 0
height = 0

for i in range(n):
  h = int(str_hlist[i])
  
  if h >= height:
    count += 1
    height = h

print(count)