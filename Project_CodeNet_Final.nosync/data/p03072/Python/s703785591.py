N = int(input())
a = [int(i) for i in input().split()]
b = a[0]
c = 0
ans = 0
for i in range(N-1):
  c += 1
  if b <= a[c] :
    b = a[c]
    ans += 1
print(ans + 1) 