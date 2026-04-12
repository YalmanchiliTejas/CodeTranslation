r, g, b = input().split()
string = r + g + b
num = int(string)
if num % 4 == 0:
    print("YES")
else:
    print("NO")