n,x=map(int, input().split())
b=[1]*51
p=[1]*51
for i in range(50):
    b[i+1]=2*b[i]+3
    p[i+1]=2*p[i]+1    

def eat(l,x):
    if x==0:
        return 0
    if l==0:
        return 1
    if x<b[l-1]+2:
        ans=eat(l-1,x-1)
    else:
        ans=p[l-1]+1+eat(l-1,x-2-b[l-1])
    return ans
print(eat(n,x))