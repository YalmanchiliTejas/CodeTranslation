S = input()
s = S[0]
flag = 0
for i in range(1, 3):
    if s != S[i]:
        flag = 1

if flag == 1:
    print('Yes')
else :
    print('No')