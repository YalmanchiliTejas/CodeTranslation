a,b,c,x,y=map(int, input().split( ))
#超過してよい
#x,y<=10000
ans=10**15

for i in range(0,max(x,y)+7):
    tmp = 2*i*c
    tmp+=max(0,(x-i)*a)
    tmp+=max(0,(y-i)*b)
    ans=min(ans, tmp)
print(ans)

