a = int(input())
b = list(map(int, input().split()))
e = b.copy()
b.sort()
c = b[a // 2 - 1]
d = b[a // 2]
for i in e:
    if i <= c:
        print(b[a // 2])
    else:
        print(b[a // 2 - 1])
