r, g, b = map(int, input().split(" "))

if g % 2 ==0 and b % 4 ==0 or g%2 ==1 and b%4==2:
    print("YES")
else:
    print("NO")