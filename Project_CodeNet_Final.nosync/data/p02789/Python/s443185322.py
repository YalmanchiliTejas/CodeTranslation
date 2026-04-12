input_line = input()
Line = input_line.split()
Line = [int(s) for s in Line]

if Line[0] == Line[1]:
    print("Yes")
else:
    print("No")