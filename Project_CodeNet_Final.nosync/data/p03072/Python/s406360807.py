N = int(input())
A = list(map(int, input().split()))
ans = 0
high = 0
for a in A:
  if high <= a:
    ans += 1
    high = a
print(ans)    
