n, x = map(int, input().split())
x -= 1

size = [1]
np = [1]

for i in range(n):
    size.append(size[-1] * 2 + 3)
    np.append(np[-1] * 2 + 1)
np.append(0)

l = 0
r = size[-1]
lv = n

ans = 0

while True:
    # print(lv, l, r, (l+r) // 2)
    mid = (l + r) // 2
    if x == mid:
        ans += np[lv-1] + 1
        break
    elif x == l:
        break
    elif x == r:
        ans += np[lv]
        break
    
    if x < mid:
        l += 1
        r = mid - 1
    else:
        ans += np[lv-1] + 1
        l = mid + 1
        r -= 1

    lv -= 1

print(ans)
    

