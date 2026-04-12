a,b,c = list(map(int,input().split()))

a = str(a)
b = str(b)
c = str(c)

num = str((a+b+c))
#print(num)

num = int(num)
if num % 4 == 0:
    print("YES")
else:
    print("NO")
