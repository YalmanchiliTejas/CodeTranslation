h,w=map(int,input().split())
a=[]
flg=True
for i in range(h):
    a.append(list(input()))
tmp=0
for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            if j<tmp:
                flg=False
            else: tmp=j
if flg:
    print("Possible")
else:
    print("Impossible")