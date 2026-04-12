n = int(input())
a = []
b = []
d = []
c = 0
for i in range(n):
 ak = int(input())
 a.append(ak)
a.sort()
for i in range((len(a)-1)//2):
 d.append(a[-i-1]-a[i])
for i in range(n-1):
 bk = a[i+1] -  a[i]
 b.append(bk)
e = len(b)
c = sum(d) * 2
if e % 2 == 1:
 c += b[e//2]
else:
 c -= min(b[e//2-1],b[e//2])
print(c)
