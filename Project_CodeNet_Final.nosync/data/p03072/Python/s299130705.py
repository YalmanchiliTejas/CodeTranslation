N = int(input())
H = []
for i in map(int,input().split()):
  H.append(i)

a = 0
ans = 0

for i in H:
  if a <= i:
    a = i
    ans += 1
print(ans)