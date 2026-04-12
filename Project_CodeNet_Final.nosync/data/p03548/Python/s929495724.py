x,y,z = map(int,input().split())
x -= y+2*z
ans = 1
while x>=0:
    x -= y+z  
    ans += 1
print(ans-1)