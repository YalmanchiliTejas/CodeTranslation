s=input()
n=len(s)

cnta=0
cntb=0

for i in range(n):
    if s[i]=='A':
        cnta+=1
    else:
        cntb+=1

if cnta>0 and cntb>0:
    print('Yes')
else:
    print('No')