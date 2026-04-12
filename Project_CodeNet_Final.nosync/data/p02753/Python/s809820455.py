s=input()
tmp=""
for i in s:
    if tmp != "":
        if tmp != i:
            print("Yes")
            exit()
    tmp = i
print("No")