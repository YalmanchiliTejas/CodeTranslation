h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
b=[["."]*w for _ in range(h)]
b[0][0]="#"
now=[0,0]
for i in range(h+w):
    if now[1]<w-1:
        if a[now[0]][now[1]+1]=="#":
            now[1]+=1
            b[now[0]][now[1]]="#"
    if now[0]<h-1:         
        if a[now[0]+1][now[1]]=="#":
            now[0]+=1
            b[now[0]][now[1]]="#"
            
print("Impossible" if a!=b else "Possible")  