def make(n,x):
    if n==0:
        return 1
    elif x==1:
        return 0
    elif x==b_memo[n-1]+2:
        return p_memo[n-1]+1
    elif x>b_memo[n-1]+1:
        return p_memo[n-1]+1+make(n-1,x-b_memo[n-1]-2)
    else:
        return make(n-1,x-1)
  
n,k=map(int,input().split())
b_memo=[0]*51
p_memo=[0]*51
b_memo[0]=1
p_memo[0]=1
for i in range(50):
    b_memo[i+1]=2*b_memo[i]+3
for i in range(50):
    p_memo[i+1]=2*p_memo[i]+1

print(make(n,k))