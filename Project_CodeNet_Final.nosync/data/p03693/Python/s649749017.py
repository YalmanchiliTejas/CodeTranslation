num = input().split()
a = int(num[0]) * 100 + int(num[1]) * 10 + int(num[2])
if a % 4 == 0:
    print("YES")
else:
    print("NO")