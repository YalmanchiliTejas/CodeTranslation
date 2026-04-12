p=[1]
b=[1]
for i in range(50):
    p.append(p[i]*2+1)
    b.append(b[i]*2+3)
def main(n,x):
    if n==0:
        if x==1:
            return 1
        return 0
    if b[n]==x:
        return p[n]
    if b[n-1]+1>=x:
        return main(n-1,x-1)
    else:
        return main(n-1,x-b[n-1]-2)+1+p[n-1]
n,x=map(int,input().split())
print(main(n,x))