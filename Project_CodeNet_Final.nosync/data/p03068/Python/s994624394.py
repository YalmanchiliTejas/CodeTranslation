a = int(input())
b = input()
c = int(input())
for i in range(len(b)):
    if b[i] != b[c-1]:
        b = b.replace(b[i],'*')
print(b)