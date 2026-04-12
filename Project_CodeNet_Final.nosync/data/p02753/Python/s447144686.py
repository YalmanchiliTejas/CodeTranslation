S=input()
a=S[0]
z=0
for i in range(len(S)):
    if a==S[i]:
        a=S[i]
    else:
        z=1

if z==0:
    print('No')
else:
    print('Yes')