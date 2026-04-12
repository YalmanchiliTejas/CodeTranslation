h,w=map(int,raw_input().split())
l=[]
#l=map(int,raw_input().split())
for i in range(h):
    l.append(list(raw_input()))
l[0][0]='.'
x=y=0
while 1:
    if x+1<w and l[y][x+1]=='#':
        x+=1
        l[y][x]='.'
    elif y+1<h and l[y+1][x]=='#':
        y+=1
        l[y][x]='.'
    else:
        break
for i in l:
    if '#' in i:
        print 'Impossible'
        exit()
print 'Possible'
