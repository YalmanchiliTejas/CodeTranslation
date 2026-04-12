list1=list(map(int,input().split()))
a=list1[0]
b=list1[1]
c=list1[2]
x=list1[3]
y=list1[4]
if x >= y:
    p = min(a * x + b * y , c * 2 * x , c * 2 * y + a * (x - y))
else:
    p = min(a * x + b * y , c * 2 * y , c * 2 * x + b * (y - x))
print(p)