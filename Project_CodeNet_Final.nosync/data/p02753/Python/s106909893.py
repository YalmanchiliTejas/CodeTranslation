s = input()

a = s[0]
b = s[1]
c = s[2]

tmp = set([a,b,c])
if(len(tmp)==1):
    print('No')
else:
    print('Yes')
