h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
max_h=0
max_w=0

for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            if max_h>i or max_w>j:
                print('Impossible')
                exit()
            else:
                max_h=max(max_h,i)
                max_w=max(max_w,j)
print('Possible')