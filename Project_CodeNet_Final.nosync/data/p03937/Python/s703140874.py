# coding: utf-8
# Your code here!
H,W=map(int,input().split())

l=[]
for _ in range(H):
    l.append(list(input()))

def dfs(h,w):
    l[h][w]="!"
    #print(l)
    #print(h,w,l[h][w])
    if h==H-1 and w==W-1:
        for item in l:
            if "#" in item:
                print("Impossible")
                exit()
        print("Possible")
        exit()
    elif (l[h-1][w]=="#" if h>0 else False) or (l[h][w-1]=="#" if w>0 else False):
        print("Impossible")
        exit()
    if h<H-1:
        if l[h+1][w]=="#":
            dfs(h+1,w)
    if w<W-1:
        if l[h][w+1]=="#":
            dfs(h,w+1)
    l[h][w]="#"
    
    return "Impossible"

print(dfs(0,0))
