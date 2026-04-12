a, b, c, x, y = map(int,input().split())

ans = 10**18

for i in range(100100):
    ans = min(ans, 2*c*i + max(0, x-i)*a + max(0,y-i)*b)
        
print(ans)