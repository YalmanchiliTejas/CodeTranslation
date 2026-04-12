s = input()
if (s[:2] == "AB" or s[:2] == "BA" or s[-2:] == "AB" or s[-2:] == "BA"):
    print("Yes")
else:
    print("No")
