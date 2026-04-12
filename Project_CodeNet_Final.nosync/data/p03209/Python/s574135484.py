#l==0 P
#l==n B+bg(l-1)+P+bg(l-1)+B
#f(n,x) returns the number of bans below x layers

#a[i] returns the size of level i burger -> a[0]=1
#b[i] returns the numbers of patties in level i burger -> b[0]=1

n,x=map(int,input().split())
a,p=[1]*(n+1),[1]*(n+1)
for i in range(n):
    a[i+1]=2*a[i]+3
    p[i+1]=2*p[i]+1

def f(n,x):
    if n==0:
        return 0 if x<=0 else 1
    elif x<=a[n-1]+1:
        return f(n-1,x-1)
    else:
        return p[n-1]+1+f(n-1,x-2-a[n-1])

print(f(n,x))