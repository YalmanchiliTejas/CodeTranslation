s = input()

lis = set()
for ss in s:
    lis.add(ss)
if len(lis) == 1:
    print('No')
else:
    print('Yes')