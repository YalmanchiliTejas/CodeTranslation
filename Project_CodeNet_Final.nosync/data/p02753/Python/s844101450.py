S = input()

c0 = None
for c in S:
    if c0 is None:
        c0 = c
        continue
    
    if c != c0:
        c0 = None
        break
    
result = "Yes" if c0 is None else "No"
print(result)