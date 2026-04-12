h,w=map(int,input().split())
for x in range(h):
    a=input()
    for i in range(w):
        if a[i]=="#":
            l=i
            break
    for j in range(w):
        if a[w-1-j]=="#":
            r=w-1-j
            break
    if x>0:
        if br>l:
            print("Impossible")
            exit()
    bl=l
    br=r
print("Possible")
