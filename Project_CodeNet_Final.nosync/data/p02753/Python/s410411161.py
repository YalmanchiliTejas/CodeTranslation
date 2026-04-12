s = input()
if all(i == "A" for i in s):
    print("No")
elif all(i == "B" for i in s):
    print("No")
else:
    print("Yes")
