x, y, z = map(int,input().split())
n = x
ans = 1

while True:
    n = (ans+1)*z + ans*y
    if n > x:
        break
    ans += 1

print(ans-1)