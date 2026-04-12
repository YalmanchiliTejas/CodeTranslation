temp = input()

judgment1 = 'A' in temp
judgment2 = 'B' in temp

if judgment1 == True:
    if judgment2 == True:
        print("Yes")
    else:
        print("No")
else:
    print('No')