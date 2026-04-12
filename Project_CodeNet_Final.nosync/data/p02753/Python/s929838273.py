tmp = ""

for s in list(input()):
    if tmp == "":
        tmp = s
        continue
    if tmp != s:
        print("Yes")
        exit()

print("No")
