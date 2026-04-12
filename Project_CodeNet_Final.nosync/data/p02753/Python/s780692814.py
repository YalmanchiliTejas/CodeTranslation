# -*- coding: utf-8 -*-
i_str = input()
stations = list(i_str)

flagA = False
flagB = False

for ss in stations:
    #print(ss)
    if ss == 'A':
        flagA = True
    elif ss == 'B':
        flagB=True

if flagA == True and flagB == True:
    print('Yes')
else:
    print('No')