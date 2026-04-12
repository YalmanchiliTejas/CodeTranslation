s=input()
b=True
for i in range(0,len(s)-1):
    if s[i:i+2]=='AC':
        print('Yes')
        b=False
        break
if b==True:print('No')