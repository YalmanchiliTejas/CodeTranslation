a=[1]
b=[1]
for i in range(50):
    a.append(3+2*a[-1])
    b.append(1+2*b[-1])
def paty(n,x):
    if n==1:return 'bpppb'[-x:].count('p')
    if x==a[n]:return b[n]
    if x==1:return 0
    if x==a[n]//2+1: return b[n-1]+1
    if x<a[n]//2+1: return paty(n-1,x-1)
    if x>a[n]//2+1: return b[n-1]+1+paty(n-1,x-a[n]//2-1)
n,x=map(int, input().split())
print(paty(n,x))