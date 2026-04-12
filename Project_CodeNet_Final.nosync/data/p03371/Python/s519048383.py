a,b,ab,x,y=map(int, input().split())
ans = 10**10
yen=0
for i in range(10**5+1):
    yen = i*2*ab + max(0, x-i)*a + max(0,y-i)*b
    ans = min(ans,yen)
print(ans)