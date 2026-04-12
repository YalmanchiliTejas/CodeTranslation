n = int(input())
i = input().split()
max = 0
m = 0
for j in range(n):
  if max <= int(i[j]):
    max = int(i[j])
    m =m + 1
    
print(m)
 