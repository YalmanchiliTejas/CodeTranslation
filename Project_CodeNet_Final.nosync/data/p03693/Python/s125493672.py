number = input().split()
number = [int(i) for i in number]
if (number[1] * 10 + number [2]) % 4 == 0:
    print("YES")
else:
    print("NO")