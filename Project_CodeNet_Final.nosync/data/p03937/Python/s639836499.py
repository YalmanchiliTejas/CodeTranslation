h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
max_h=0
max_w=0
flag=True
for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            if i>max_h:
                max_h=i
            elif i<max_h:
                flag=False
            if j>max_w:
                max_w=j
            elif j<max_w:
                flag=False
print("Possible" if flag==True else 'Impossible')