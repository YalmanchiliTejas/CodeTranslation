n = int(input())
h=[int (i) for i in input().split()]

ans = 0
max_h = 0
for i in h:
  if i >= max_h:
    ans += 1
    max_h = i
    
print(ans)