s = list(str(input()))


arr = list(set(s))
if len(arr) == 2:
    print('Yes')
else:
    print('No')
