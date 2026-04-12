a,b,c,x,y = map(int, open(0).read().split())

ans = 1 << 31

for i in range(max(x,y)+1):
    ans = min(ans, i*2*c + max(x-i, 0)*a + max(y-i, 0)*b)

print(ans)