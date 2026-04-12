a = int(input())
b = list(input())
c = int(input())
d = b[c-1]

for i in range(a):
    if b[i] == d:
        print(d,end = "")
    else:
        print("*",end = "")

print("")
