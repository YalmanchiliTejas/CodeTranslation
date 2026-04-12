#14:22
n,k = map(int,input().split())
whole = [1]
patty = [1]
for _ in range(n):
  whole.append(whole[-1] * 2 + 3)
  patty.append(patty[-1] * 2 + 1)
ans = 0
rest = k
for i in range(n,-1,-1):
  if i == 0:
    ans += [0,1,2,3,3][rest]
    rest = 0
  elif rest <= whole[i] - (i-1):
    rest -= 1
  elif rest <= whole[i]:
    rest = 0
    ans += patty[i]
  elif rest == whole[i] + 1:
    rest -= whole[i] + 1
    ans += patty[i] + 1
  else:
    rest -= whole[i] + 2
    ans += patty[i] + 1
  if rest == 0:
    print(ans)
    break