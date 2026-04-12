input()
a = [int(i) for i in input().split()]

max = -1
ans = 0

for i in a:
  if i >= max:
    max = i
    ans = ans + 1
  
print(ans)