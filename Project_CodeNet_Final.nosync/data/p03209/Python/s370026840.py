def f(n,x):
    if n==0:
        return 1
    elif x==1:
        return 0
    elif x==b_memo[n]//2+1:
        return p_memo[n-1]+1
    elif x<=b_memo[n]//2:
        return f(n-1,x-1)
    else:
        return 1+p_memo[n-1]+f(n-1,x-b_memo[n-1]-2)

n,x=map(int,input().split())

b_memo=[0]*51
p_memo=[0]*51
b_memo[0]=1
p_memo[0]=1

for i in range(50):
    b_memo[i+1]=b_memo[i]*2+3
    p_memo[i+1]=p_memo[i]*2+1
    
print(f(n,x))