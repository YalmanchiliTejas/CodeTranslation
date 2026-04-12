n,x,m = map(int,input().split())

li = [x]
a = x
q = 0
flag = False
for i in range(m):
    k = (a**2)%m
    if k == 0:
        p = i+1
        flag = True
        break
    if k in li:
        p = i+1
        q = li.index(k)
        break
    li.append(k)
    a = k
    
K = sum(li)
li2 = li[q:]
K2 = sum(li2)

if not flag:
    ans = K + ((n-p)//(p-q))*K2 + sum(li2[:((n-p)%(p-q))])
else:
    ans = sum(li[:n])
print(ans)