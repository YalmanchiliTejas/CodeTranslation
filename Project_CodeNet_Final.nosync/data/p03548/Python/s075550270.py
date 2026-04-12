x,y,z = map(int,input().split())

ans = 0

while y * ans + z * (ans+1) <= x:
    ans += 1

print(ans-1)
