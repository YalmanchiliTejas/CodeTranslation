n, x, m = map(int, input().split())
d = [0]*(m+1)
check = [x]
tmp = x
for i in range(1, n):
    tmp = (tmp**2)%m
    if d[tmp]: break
    d[tmp] = 1
    check.append(tmp)

for i in range(len(check)):
    if tmp == check[i]:
        index = i
        break
sum_c = sum(check[index:])
ans = sum(check)
nokori = n - len(check)
kuri = nokori//len(check[index:])
ans += kuri*sum_c
nokori -= kuri*len(check[index:])
ans += sum(check[index:index+nokori])
print(ans)