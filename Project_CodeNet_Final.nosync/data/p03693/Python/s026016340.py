r,g,b = map(int,input().split())

temp = 100*r + 10*g + b

#print(temp)

if temp % 4 == 0:
    print("YES")

else:
    print("NO")
