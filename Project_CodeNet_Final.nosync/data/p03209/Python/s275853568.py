n, x = map(int, input().split())

memol = {0: 1}
memop = {0: 1}


for i in range(1, n+1):
    memol[i] = memol[i-1] * 2 + 3
    memop[i] = memop[i-1] * 2 + 1

ret = 0
ln = 0
for i in range(n, -1, -1):
    if ln >= x:
        break
    ln += 1
    if ln >= x:
        break
    if ln + memol[i-1] > x:
        continue
    ln += memol[i-1]
    ret += memop[i-1]
    if ln == x:
        break
    ln += 1
    ret += 1
    if ln + memol[i-1] > x:
        continue
    ln += memol[i-1]
    ret += memop[i-1]
    if ln == x:
        break
    ln += 1

print(ret)
