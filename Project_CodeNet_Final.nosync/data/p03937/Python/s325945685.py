import sys
input=sys.stdin.readline
h,w=map(int,input().split())
a=[]
for i in range(h):
    sub=input().rstrip()
    a.append(sub)
check=True
for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            for k in range(h):
                for l in range(w):
                    if (i>k and j<l) or (i<k and j>l):
                        if a[k][l]=='#':
                            check=False
if check:
    print('Possible')
else:
    print('Impossible')

