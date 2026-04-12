s=input()
a=False
b=False
for i in range(len(s)):
    if s[i]=='A':
        a=True
    if s[i]=='B':
        b=True
if a and b:
    print('Yes')
else:
    print('No')