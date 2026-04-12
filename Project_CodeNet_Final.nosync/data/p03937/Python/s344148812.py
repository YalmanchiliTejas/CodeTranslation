h,w = map(int,input().split())
field = [list(input()) for i in range(h)]
 
tmp=0
for i in range(h):
    for j in range(w):
        if field[i][j]=='#':
            tmp+=1
if (h+w-1)==tmp:
    print('Possible')
else:
    print('Impossible')