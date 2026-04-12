n, x, m = map(int, input().split())

lis = [x]
flag = [-1 for i in range(m)]
flag[x] = 0
left = -1
right = -1
for i in range(n-1):
    x = x**2 % m
    if flag[x] >= 0:
        left = flag[x]
        right = i
        break
    else:
        lis.append(x)
        flag[x] = i+1

ans = 0
if left == -1:
    ans = sum(lis)
else:
    ans += sum(lis[0:left])
    length = right - left + 1
    ans += sum(lis[left:]) * ((n-left)//length)
    ans += sum(lis[left:left+((n-left)%length)])
print(ans)