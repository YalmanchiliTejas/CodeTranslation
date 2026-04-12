def getInput():
    return list(input().rstrip())

S = getInput()
a = ['A' for i in range(3)]
b = ['B' for i in range(3)]

if (a == S or b == S): print('No');
else: print('Yes');