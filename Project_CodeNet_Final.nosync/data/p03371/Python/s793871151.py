def LI():return map(int,input().split())
def I(): return input().split()

a,b,c,x,y=LI()
lst=[]
ans=0
for i in range(10**5+1):
    lst.append(2*i*c+max(0,x-i)*a+max(0,y-i)*b)
print(min(lst))