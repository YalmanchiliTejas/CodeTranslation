s=input()
if len(s)==1:
    print('No')
else:
    if s.count('BA')>=1 or s.count('AB')>=1:
        print('Yes')
    else:
        print('No')
