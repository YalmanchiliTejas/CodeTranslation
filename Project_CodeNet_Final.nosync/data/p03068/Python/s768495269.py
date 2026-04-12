def solve():
  n = int(input())
  s = input()
  k = int(input())
  ans = ""
  place = s[k-1]
  #print(place)
  for i in s:
    if i != place:
      ans += '*'
    else:
      ans += place
  print(ans)
solve()