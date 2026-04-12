S = input()

cb=ca=0
for i in S:
    if (i=='A'):
        ca+=1

    elif (i=='B'):
        cb+=1
if(ca==3 or cb==3):
    print('No')
else:
    print('Yes')