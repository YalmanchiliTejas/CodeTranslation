n = int(input())

ss = []
mins = 'a'*100
for _ in range(n):
  s = str(''.join(sorted(input())))
  ss.append(s)
  if len(mins) > len(s):
    mins = s
  
ans = ''
for w in mins:
  ok = True
  for i, s in enumerate(ss[:]):
    if w in s:
      wi = s.find(w)
      ss[i] = s[:wi] + s[wi+1:]
    else:
      ok = False
  if ok:
    ans += w
print(ans)