n=int(input())
s=[''.join(sorted(input())) for _ in range(n)]
s0=s[0]
for i in range(n):
  s0_copy=s0
  si=s[i]
  for c in s0_copy:
    if c in si:
      si=si.replace(c,'',1)
    else:
      s0=s0.replace(c,'',1)
print(s0)