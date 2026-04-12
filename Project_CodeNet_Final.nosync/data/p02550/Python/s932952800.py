n, x, m = map(int,input().split())
lst = [0 for i in range(m)]
lst2 = [x]
i = 2
lst[x] = 1
c = 0
while True:
    if (i > n):
        break
    x = x**2%m
    if (lst[x] == 0):
        lst[x] = i
        lst2.append(lst2[i - 2] + x)
        i = i + 1
    else:
        lst2.append(lst2[i - 2] + x)
        c = 1
        break
if (c == 1):
    a = i - lst[x]
    b = lst2[i - 1] - lst2[i - 1 - a]

    c = (n - i)//a
    d = (n - i)%a
    ans = lst2[i - 1] + b*c + lst2[i - 1 - a + d] - lst2[i - 1 - a]
    print(ans)

else:
    print(lst2[n - 1])
