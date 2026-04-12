n, x = map(int, input().split())
def all_putty(m):
 return 2**(m+1)-1
count = 0
for l in range(n+1)[::-1]:
  mark = 2**(1+l)-1
  if x >= mark:
    count += all_putty(l-1) +1
    x -= mark
  else:
    x -= 1
print(count)