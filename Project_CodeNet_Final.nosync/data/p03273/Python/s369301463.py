H,W=map(int,input().split())
a=[]
for i in range(H):
    a.append(str(input()))

cnt=0
while cnt<H:
    if a[cnt]=='.'*W:
        H-=1
        del a[cnt]
    else:
        cnt+=1

cnt=0
while cnt<W:
    for s in a:
        if s[cnt]=='#':
            cnt+=1
            break
        elif s==a[H-1]:
            W-=1
            for i in range(H):
                a[i]=a[i][:cnt]+a[i][cnt+1:]

            
for s in a:
    print(s)