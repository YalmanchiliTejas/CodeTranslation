a, b, ab, x, y = list(map(int, input().split()))

ab1 = ab * 2
abp = a + b
mins = min(x, y)
maxs = max(x, y)
nedan = min(ab1, abp) * mins

x -= mins
y -= mins
nedan_abp = x * a + y * b
nedan_ab = (maxs - mins) * ab1

if nedan_abp > nedan_ab:
  nedan += nedan_ab
else:
  nedan += nedan_abp
  
print(nedan)