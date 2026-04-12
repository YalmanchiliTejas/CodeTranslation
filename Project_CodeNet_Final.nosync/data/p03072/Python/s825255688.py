N = int(input())
H = [int(i) for i in input().split()]

ans = 0
hh = 0
for h in H:
  if hh <= h:
    ans += 1
    hh = h

print(ans)


