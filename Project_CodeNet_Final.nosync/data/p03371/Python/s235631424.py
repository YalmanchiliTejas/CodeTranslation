a,b,c,x,y = map(int,input().split())
all_ab = max(x,y) * 2
ans = a*x + b*y

for i in range(2,all_ab+1,2):
    cnt = i*c
    alt = int(i/2)
    need_a = max(x - alt, 0)
    need_b = max(y - alt, 0)
    cnt += a*need_a + b*need_b
    ans = min(ans, cnt)
    # print(i,ans)

print(ans)