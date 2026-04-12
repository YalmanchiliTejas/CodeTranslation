N = int(input())
H = list(map(int,input().split()))

ans = 0
top = H[0]

for i in H:
  if i == top:
    ans += 1
  elif i > top:
    top = i
    ans += 1

print(ans)