x, y, z = map(int, input().split())
ans = 2*z+y

for i in range(2, 1000002): 
    ans += y+z
    if(ans >= x):
        print(i-1 if ans > x else i)
        break