a,b,c,x,y = map(int,input().split())

if x > y:
    tmp1 = a
    tmp2 = x
    a = b
    b = tmp1
    x = y
    y = tmp2
    
arr = []

arr.append(a*x+b*y)
arr.append(b*y+(2*c-b)*x)
arr.append(2*c*y)

print(min(arr))