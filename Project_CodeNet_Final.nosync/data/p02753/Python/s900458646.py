a = input()
flag = False
if (a[0] == a[1]) and (a[1] == a[2]):
    flag = False
else:
    flag = True
if flag:
    print('Yes')
else:
    print('No')