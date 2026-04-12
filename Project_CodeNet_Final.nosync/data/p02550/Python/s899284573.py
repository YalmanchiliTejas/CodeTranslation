n, x, m = [int(x) for x in input().split()]
val = [0, x]
d = {x}
prev = x
ans = x
for i in range(2, n+1):
    cur = prev*prev%m
    if cur==0:
        break
    if cur in d:
        pos = val.index(cur)
        length = len(val)-pos
        left = n-i+1
        temp = 0
        for j in range(pos, len(val)):
            temp += val[j]
        ans += (left//length)*temp
        left -= (left//length)*length
        while left:
            ans += val[pos]
            pos += 1
            left-= 1
        break
    else:
        ans += cur
        prev = cur
        d.add(cur), val.append(cur)

print(ans)
