n,x = map(int,input().split())

b = [1]
l = [1]
for i in range(n):
    b.append(b[-1]*2+1)
    l.append(l[-1]*2+3)

#print(*b)
#print(*l)

x -= 1
res = 0
lv = n
while lv >= 0:
    #print(x,lv,l[lv],b[lv],res)
    if lv == 0:
        res += 1
        break
    elif x <= 0:
        break
    elif x >= l[lv]-1:
        res += b[lv]
        break
    elif x == l[lv] // 2:
        res += b[lv-1] + 1
        break
    elif x > l[lv] // 2:
        res += b[lv-1] + 1
        lv -= 1
        x -= l[lv] + 2
    else:
        lv -= 1
        x -= 1
print(res)
