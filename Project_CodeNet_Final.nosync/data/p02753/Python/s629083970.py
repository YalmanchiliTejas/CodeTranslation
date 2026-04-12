s = list(input())

p = list(set(s))
if len(p) == 1:
    print('No')
else:
    print('Yes')