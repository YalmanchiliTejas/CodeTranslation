a,b,c,x,y = map(int,input().split())

aaa = min(x,y) * min(a + b,2 * c)

aaa += max(0,x - y) * min(a,2 * c)
aaa += max(0,y - x) * min(b,2 * c)

print(aaa)
