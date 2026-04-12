a = int(input())
b = input()
c = int(input())
d = b[c-1]
for i in range(a):
    if b[i]!=d :
        b = b.replace(b[i],'*')
print(b)