h,w=map(int,input().split())
a=[[0 for _ in range(h)] for _ in range(w)]
ans=[]
#print(a)
for i in range(h):
    b=list(input())#w nonagasa 
    if '#'  in b:
        for j in range(w):
            a[j][i]=b[j]
#for i in range(w):
    #print(a[i])
c=0
for i in range(0-c,w-c):
    if '#' not in a[i]:
        for j in range(h):
            a[i][j]=0
for i in range(h):
    for j in range(w):
        if a[j][i]!=0:
            print(a[j][i],end="")
            c+=1
    if c!=0:
        print()
    c=0


                
        