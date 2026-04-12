S = str(input())
AC = 0
for i in range(len(S) - 1):
    if S[i] == 'A' and S[i+1] =='C':
        AC = 1
if AC == 1:
    print('Yes')
else:
    print('No')