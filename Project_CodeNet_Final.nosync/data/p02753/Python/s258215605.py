S = list(input())

flag = 1

if S[0] == S[1] and S[1] == S[2]:
    flag = 0

if flag == 1:
    print('Yes')
else:
    print('No')