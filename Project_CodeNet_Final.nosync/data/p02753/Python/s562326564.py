# A - Station and Bus
s = input()

cntA = 0
cntB = 0

for i in s:
    if i == 'A':
        cntA += 1

    else:
        cntB += 1

if cntA == 3 or cntB == 3:
    print('No')
else:
    print('Yes')