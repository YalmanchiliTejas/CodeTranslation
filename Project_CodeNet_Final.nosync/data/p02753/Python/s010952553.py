s = input()

flag = False

for i in range(3):
    for j in range(3):
        if s[i] != s[j]:
            flag = True

if flag:
    print('Yes')
else:
    print('No')
