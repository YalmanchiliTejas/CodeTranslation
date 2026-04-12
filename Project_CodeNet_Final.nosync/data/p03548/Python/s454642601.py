a,b,c=map(int,input().split())
n=a//(b+c)
m=a-n*(b+c)
if m//c==1:
    print(n)
else:
    print(n-1)