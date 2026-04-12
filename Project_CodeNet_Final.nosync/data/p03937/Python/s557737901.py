H,W=(map(int,input().split()))
count=0
for i in range(H):
    a=list(input())
    for i in a:
        if i=='#':
            count+=1
if count==H+W-1:
    print('Possible')
else:
    print('Impossible')