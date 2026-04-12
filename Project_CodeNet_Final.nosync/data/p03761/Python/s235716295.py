n =int(input())
ls=[]
for i in range(n):
    s=input()
    ls.append([c for c in s])

res = []
for c1 in ls[0]:
    flag = 0
    for i in range(1,n):
        if c1 in ls[i]:
            ls[i].remove(c1)
            flag += 1
    if flag == n-1:
        res.append(c1)
res.sort()
print("".join(res))