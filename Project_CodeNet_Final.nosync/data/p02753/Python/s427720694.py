raw_input = input()
l = list(raw_input)

if l[0] == l[1]:
    if l[1] == l[2]:
        print("No")
    else:
        print("Yes")
else:
    print("Yes")