s = input()
if all(si == 'A' for si in s) or all(si == 'B' for si in s):
    print('No')
else:
    print('Yes')
