gomi = input()
a = input()
b = int(input())
c = []
for i in range(len(a)):
    if a[b-1] == a[i]:
        c.append(a[i])
    else:
        c.append("*")

print(''.join(c))