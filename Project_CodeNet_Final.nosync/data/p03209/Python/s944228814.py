n,x = list(map(int,input().split()))
def cal(n,x):
    if n==0:
        return 1
    if x==1:
        return 0
    ll = 2**(n+1)-3
    if x<=ll+1:
        return cal(n-1,x-1)
    if x==ll+2:
        return cal(n-1,x-2)+1
    if x<=ll+ll+2:
        return cal(n-1,ll)+1+cal(n-1,x-ll-2)
    if x==ll+ll+3:
        return 2**(n+1)-1

print(cal(n,x))