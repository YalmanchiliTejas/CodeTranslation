n = int(input())
list = list(map(int,input().split()))
x = 0
for i in range(n):
  j = 0
  while j <= i and list[i] >= list[j]:
    if i == j:
      x += 1
    j += 1
print(x)
  
    

  