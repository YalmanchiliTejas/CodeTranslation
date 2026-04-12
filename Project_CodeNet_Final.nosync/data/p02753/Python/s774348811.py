s = raw_input().strip()

ss = set()

for c in s:
  ss.add(c)

  
print("Yes" if len(ss) == 2 else "No")