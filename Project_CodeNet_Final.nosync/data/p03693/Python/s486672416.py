r,g,b = input().split()

number = r+g+b

if int(number)%4 == 0:
    print("YES")
else:
    print("NO")

