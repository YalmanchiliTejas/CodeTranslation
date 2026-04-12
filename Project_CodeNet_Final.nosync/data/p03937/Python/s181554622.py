import sys
h,w=map(int,raw_input().split())
a=[list(raw_input()) for _ in range(h)]
b=[['.']*w for _ in range(h)]
i=j=0
flag=True
while flag:
    b[i][j]='#'
    if (i,j)==(h-1,w-1):break
    flag=False
    if i+1<h:
        if a[i+1][j]=='#':i+=1;flag=True
    if not flag and j+1<w:
        if a[i][j+1]=='#':j+=1;flag=True
if a==b:print 'Possible'
else:print 'Impossible'
