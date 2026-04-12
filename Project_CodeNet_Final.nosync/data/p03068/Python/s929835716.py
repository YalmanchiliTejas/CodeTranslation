nons = input()
a = input()
b = list(a)
c= int(input())
d = b[c-1]
result = str()
for i in range(0,len(b)):
    if b[i] == d:
        pass
    else:
        b[i] = '*'
for i in range(len(b)):
    result = result+b[i]
print(result)
