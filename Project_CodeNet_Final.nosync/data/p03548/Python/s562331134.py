i = input().split()
x = int(i[0])
y = int(i[1])
z = int(i[2])
flag = True
n = 0
while(flag):
    n = n + 1
    if x< n*y + (n+1)* z:
        flag = False
print(n-1)
