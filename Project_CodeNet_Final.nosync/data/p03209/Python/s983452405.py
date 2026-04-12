n,x=map(int,input().split())

arr=[1]*(n+1)
patty=[1]*(n+1)
for i in range(n):
    arr[i+1]=3+2*arr[i]
    patty[i+1]=1+2*patty[i]

def f(n,x):
    
    if n==0:
        return 1
    elif x==1:
        return 0
    elif x==arr[n] or x==arr[n]-1:
        return patty[n]
    elif x<arr[n]//2+1:
        return f(n-1,x-1)
    elif x==arr[n]//2+1:
        return patty[n-1]+1
    else:
        return patty[n]-f(n-1,arr[n]-x-1)

print(f(n,x))