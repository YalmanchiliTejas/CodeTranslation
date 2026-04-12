input()
t = list(map(int,input().split()))
hmax = 0
ans = 0
for h in t:
    if(hmax <= h):
        ans += 1
        hmax = h
print(ans)