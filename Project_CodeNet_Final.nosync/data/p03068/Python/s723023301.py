a = int(input())
b = input()
c = int(input())
z = b[c-1]
for i in b:
    if not i == z:
        print("*", end="")
    else:
        print(i, end="")