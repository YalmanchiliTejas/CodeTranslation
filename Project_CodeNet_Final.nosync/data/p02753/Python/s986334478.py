s = input()
a = set()
for x in s:
    a.add(x)
if len(a) == 1:
    print('No')
else:
    print('Yes')