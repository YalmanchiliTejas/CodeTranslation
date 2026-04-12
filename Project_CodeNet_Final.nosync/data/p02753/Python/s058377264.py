S = list(str(input()))
flgA = 0
flgB = 0
for i in range(3):
    if S[i] == 'A':
        flgA = 1
    elif S[i] == 'B':
        flgB =1

if flgA == 1 and flgB ==1:
    print('Yes')
else:
    print('No')
