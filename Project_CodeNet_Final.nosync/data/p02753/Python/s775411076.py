s = input()
flag = True
for i in range(len(s)-1):
    if s[i] != s[i+1]:
        flag = False
if flag:
    print('No')
else:
    print('Yes')