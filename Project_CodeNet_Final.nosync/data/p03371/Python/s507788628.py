a,b,c,x,y = map(int,input().split())
ans = 10**20

for i in range(2*10**5+1):
    ai = max(0, x-i//2)
    bi = max(0, y-i//2)
    ans = min(ans, ai*a + bi*b + i*c)

print(ans)

