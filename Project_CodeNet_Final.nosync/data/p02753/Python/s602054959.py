n=input()
a=0
for i in n:
    if i=="A":
        a+=1
if a%3!=0:
    print('Yes')
else:
    print('No')
