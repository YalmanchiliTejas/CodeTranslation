r, g, b = map(str, input().split())
num = int(r+g+b)
if num % 4:
    print("NO")
else :
    print("YES")