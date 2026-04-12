
x = int(input())

if (x / 7 <= 1 and x % 7 == 0)  or (x / 5<= 1 and x % 5 == 0) or (x / 3 <= 1 and x % 3 == 0):
    print("YES")
else:
    print("NO")