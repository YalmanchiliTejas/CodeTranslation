s = input()

if all((s[i] == 'A' for i in range(3))):
    print('No')
elif all((s[i] == 'B' for i in range(3))):
    print('No')
else:
    print('Yes')
