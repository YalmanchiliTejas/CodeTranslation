n,m,c = int(raw_input()),-float('inf'), 0
for e in map(int, raw_input().split(' ')):
  c += 1 if m <= e else 0
  m = max(e, m)
print c