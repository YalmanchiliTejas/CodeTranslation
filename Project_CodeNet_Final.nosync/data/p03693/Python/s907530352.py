s = input().split()

r = s[0]
g = s[1]
b = s[2]

result = r + g + b
if int(result) % 4 == 0:
    print("YES")
else:
    print("NO")