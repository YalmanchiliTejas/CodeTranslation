N = int(input())
Hs = input().split(" ")

H = 0
res = 0

for i in range(N):
  if int(H) <= int(Hs[i]):
    res += 1
    H = Hs[i]

print(res)