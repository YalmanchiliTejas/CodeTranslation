li = list(map(int,input().split()))
so = sorted(li)
a = so[0]
b = so[4]
c = so[8]
for n in so[:4]:
    res1=  a==n
for n in so[4:8]:
    res2=  b==n
for n in so[8:]:
    res3= c==n
res = 'yes' if res1 and res3 and res2 else 'no'
print(res)
