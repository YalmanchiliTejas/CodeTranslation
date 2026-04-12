s = input()
flag = 0
for i in s:
    if i == 'A':
        flag = 1
        continue
    if i == 'C' and flag == 1:
        print('Yes')
        exit()
    flag = 0
print('No')
