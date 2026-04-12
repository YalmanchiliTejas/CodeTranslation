n, x, m = map(int, input().split())
num = {x}
num2 = [x]
while True:
    temp = num2[-1] ** 2 % m
    if temp in num:
        break
    else:
        num.add(temp)
        num2.append(temp)
temp2 = num2.index(temp)
num3 = num2[:temp2]
num4 = num2[temp2:]
ans = sum(num3) + sum(num4) * ((n - len(num3)) // len(num4)) + sum(num4[:(n - len(num3)) % len(num4)])
print(ans)