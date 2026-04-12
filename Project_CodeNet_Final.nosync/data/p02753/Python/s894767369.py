a=input()
len=len(a)
a_cnt=0
b_cnt=0
for i in range(len):
    if a[i]=='A':
        a_cnt+=1
    else :
        b_cnt+=1
if a_cnt>0 and b_cnt>0:
    print('Yes')
else :
    print('No')
