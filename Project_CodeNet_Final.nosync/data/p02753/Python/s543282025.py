S=str(input())
result=0
if 'A' in S:
    if 'B' in S:
        result+=1
elif 'B' in S:
    if 'A' in S:
        result+=1
if result>=1:
    print('Yes')
else:
    print('No')