input_lines = input().split(" ")
X = int(input_lines[0])
Y = int(input_lines[1])
Z = int(input_lines[2])

judge = X//(Y+Z)

if judge*(Y+Z)+Z>X:
    print(str(X//(Y+Z)-1))
else:
    print(str(X//(Y+Z)))
