a = int(input())
b = list(str(input()))
c = int(input())

moji = b[c - 1]

for i in range(a):
    if b[i] != moji:
        b[i] = '*'

b = ''.join(b)
print(b)