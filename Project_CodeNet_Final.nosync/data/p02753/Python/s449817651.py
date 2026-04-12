stations = input()
numA = 0
numB = 0
for station in stations:
    if station == 'A':
        numA +=1
    else:
        numB += 1
if (numA > 2 or numB > 2):
    print('No')
else:
    print('Yes')