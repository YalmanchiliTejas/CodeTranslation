a , b , c , x , y = map(int,input().split())
ans = 10**10

for i in range(10**5+1):
    ans = min(ans, a * max(x -i,0) + b * max(y - i , 0)  + (2 * c * i)  )
print(ans)