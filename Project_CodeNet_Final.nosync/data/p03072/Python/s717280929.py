N = int(input())
H = list(map(int, input().split()))
S = 0
m = 0
for h in H:
  if m<=h:
    S += 1
  m = max(m, h)
print(S)