import sys

S = str(input().strip('\n'))

if len(S) != 3 or S == 'AAA' or S == 'BBB':
    print('No')
    sys.exit()
else:
    for Count in range(1,4):
        if S[Count-1] =='A' or \
           S[Count-1] =='B':
            pass
        else:
            print('No')
            sys.exit()

print('Yes')
