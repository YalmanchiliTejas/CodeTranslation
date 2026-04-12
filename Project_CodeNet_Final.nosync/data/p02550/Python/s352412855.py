n, x, m = list(map(int, input().split()))
a = [x]
start = -1
end = -1
check = [0]*m
path = -1
loop = 0

for i in range(1, n):
    ans = (a[i-1]**2) % m
    p = check[ans]
    if p != 0:
        if start == -1:
            start = i
            path = ans
        if p == 1:
            end = i
    if p >= 3:
        break
    check[ans] += 1
    a.append(ans)


if start == -1 or end == -1:
    print(sum(a))
else:
    lenght = end-start+1
    loop, mod = divmod(n-start, lenght)
    ans = sum(a[:start])+sum(a[start:end+1])*loop + sum(a[start:start+mod])
    print(ans)