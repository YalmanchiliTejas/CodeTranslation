inputs = input()

x = list(inputs)

flag = False
for i in range(len(x) - 1):
    if x[i] == 'A' and x[i+1] == 'C':
        flag = True

if flag:
    print('Yes')
else:
    print('No')