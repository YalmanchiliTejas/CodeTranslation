# coding: utf-8
# Your code here!
x,y,z=map(int,input().split())
n=1#最初は一人
while True:
    l=y*n+(n+1)*z
    if l>x:
        break
    else:
        n+=1
        ans=n
ans-=1
print(ans)