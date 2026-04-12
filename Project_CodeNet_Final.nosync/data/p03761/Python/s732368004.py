# -*- coding: utf-8 -*-


N = int(input())
Sn = [str(input()) for _ in range(N)]

ans = Sn.pop()
while len(Sn) > 0:
  s = list(Sn.pop())
  t = ans
  ans = ""
  for c in t:
    if c in s:
      ans += c
      s.remove(c)

print("".join(sorted(ans)))