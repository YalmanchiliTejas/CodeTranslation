str = input()
numlist = str.split(' ')
a = int(numlist[0])
b = int(numlist[1])
if a < b:
    print("a < b")
elif a > b:
    print("a > b")
else:
    print("a == b")