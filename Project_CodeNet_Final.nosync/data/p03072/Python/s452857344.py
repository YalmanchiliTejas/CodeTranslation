N = input()
Hi = list(map(int, input().split()))
a = Hi[0]
b = 0
c = 0
for i in Hi:
    # print(i)
    if i >= c:
        b += 1
        c = i
print(b)