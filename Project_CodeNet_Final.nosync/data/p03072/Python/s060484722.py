N = int(input())
H = list(map(int, input().split()))
m = 0
ans = 0
for h in H:
  if m <= h:
    ans += 1
  m = m if m > h else h
print(ans)