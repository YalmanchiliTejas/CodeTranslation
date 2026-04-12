S = input()
flag = False
for i in range(3):
    if S[i] != S[0]:
        flag = True

if flag:
    print('Yes')
else:
    print('No')