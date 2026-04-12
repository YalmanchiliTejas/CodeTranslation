N = int(input())
H = list(map(int, input().split()))
templist = [0]
ans = 0

for i in range(N):
  templist.append(H[i])
  if H[i] >= max(templist):
    ans += 1

print(ans)