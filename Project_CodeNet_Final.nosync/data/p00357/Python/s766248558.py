n = int(input())
j = 0
t = 10
for i in range(n):
    if j < i:
        print("no")
        break
    d = int(input())
    j += d // 10
    if d < t:
        t += 10
    elif d >= t:
        t = 10
else:
    if t == 10:
        print("yes")
    else:
        print("no")
