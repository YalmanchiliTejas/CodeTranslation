h, w = map(int, input().split())
s = []
for i in range(h):
  _s = input()
  if '#' in _s:
    s.append(_s)
    
deletes = []
for j in range(w):
  for i in range(len(s)):
    if s[i][j] == '#':
      break
  else:
    deletes.append(j)
    
for i in range(len(s)):
  out = ''
  for j in range(len(s[i])):
    if not j in deletes:
      out += s[i][j]
  print(out)
  