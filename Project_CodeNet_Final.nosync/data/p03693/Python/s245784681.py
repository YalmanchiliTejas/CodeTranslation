a,b,c = map(int, input().split())

num = a*100 + b*10 + c

if(num % 4 == 0):
    print("YES")
else:
    print("NO")