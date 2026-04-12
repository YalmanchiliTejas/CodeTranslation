# coding: utf-8
# Your code here!
N,X=map(int,input().split())

X-=1
def saiki(i,x,count):
    if i==-1:
        print(int(count)+1)
        exit()
    all=2**(i+2)-3
    paty=2**(i+1)-1
    if x==all-1:
        print(count+paty)
        exit()
    elif x==0:
        print(count)
    elif x==(all-1)//2:
        print(int(count+(paty-1)//2+1))
        exit()
    elif x>(all-1)//2:
        count+=((paty-1)//2+1)
        x-=(all//2)
        saiki(i-1,x-1,count)
    elif x<(all-1)//2:
        saiki(i-1,x-1,count)
    

ans=0
saiki(N,X,ans)

