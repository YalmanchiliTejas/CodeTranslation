a = input()
for i in range(len(a)-1):
    b = a[i:i+2]
    if b == "AC":
        print("Yes")
        exit()
print("No")