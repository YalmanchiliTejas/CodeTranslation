s = input()
temp = set()
for i in range(3):
    temp.add(s[i])
if len(temp) == 1:
    print('No')
else:
    print('Yes')
