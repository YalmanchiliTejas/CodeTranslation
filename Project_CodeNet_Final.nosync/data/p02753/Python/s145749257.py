S = input()
result = set()

for s in S:
  result.add(s)

if len(result) == 2:
  ans = 'Yes'
else:
  ans = 'No'

print(ans)