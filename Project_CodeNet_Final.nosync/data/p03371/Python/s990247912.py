a,b,c,x,y=map(int,input().split())
m=10**9
for i in range(0,max(x,y)*2+1,2):
    p=(c*i)+max((b*(y-(i//2))),0)+max((a*(x-(i//2))),0)
    if p<m:
        m=p
print(m)
