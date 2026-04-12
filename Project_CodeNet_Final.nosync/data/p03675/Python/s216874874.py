# cook your dish here
n = int(input())
a = list(map(int,input().split()))
c = []
d = []

for i in range(n):
    if i %2 == 0:
        c.append(a[i])
    else:
        d.append(a[i])
c = c[::-1]

b = c + d
c = b[::-1]
ass = ''
for i in range(n):
    if n %2 == 0:
        ass += str(c[i]) + ' '
    else:
        ass += str(b[i]) + ' '
print(ass)