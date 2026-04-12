S = str(input())

cnt1=0
cnt2=0
for i in S:
    if i=='A':
        cnt1+=1
    else:
        cnt2+=1
if cnt1>=1 and cnt2>=1:
    print('Yes')
else:
    print('No')
