h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
x,y=0,0
while(x<h and y<w):
    a[x][y]='.'
    if y+1<w and a[x][y+1]=="#":
        y+=1
    elif x+1<h and a[x+1][y]=="#":
        x+=1
    else:
        break
j=True
for b in a:
    for t in b:
        if t=="#":
            j=False
            break
print("Possible" if j else "Impossible")