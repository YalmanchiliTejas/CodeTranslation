def LI():return map(int,input().split())
def I(): return input().split()

a,b,c,x,y=LI()
lst=0
ans=float("inf")
for i in range(10**5+1):
    ans=min(ans,(2*i*c+max(0,x-i)*a+max(0,y-i)*b))
print(ans)