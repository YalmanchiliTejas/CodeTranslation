l = list(map(int,input().split()))
a,b,c,x,y = l[0],l[1],l[2],l[3],l[4]
ans = 0
minxy = min(x,y)
maxxy = max(x,y)
if maxxy == x:
    remab = a
elif maxxy == y:
    remab = b
rem = maxxy - minxy
if a + b >= 2*c:
    ans += 2*minxy*c
else:
    ans += minxy*(a+b)
if rem == 0:
    print(ans)
else:
    if 2*c <= remab:
        ans += 2*rem*c
    else:
        ans += rem*remab
    print(ans)