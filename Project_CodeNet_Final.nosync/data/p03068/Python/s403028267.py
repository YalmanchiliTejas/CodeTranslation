a = int(input())
b = list(input())
c = int(input())
z = b[c-1]
for i in range(a):
    if not b[i] == z:
        b[i] = "*"
print(*b, sep="")