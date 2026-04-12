val = input()

if val[0:1] == val[1:2] and val[0:1] == val[2:3] and val[1:2] == val[2:3]:
    print("No")
else:
    print("Yes")