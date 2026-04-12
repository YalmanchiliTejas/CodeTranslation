rgb = [int(i) for i in input().split()]
num = 0
for i, n in enumerate(reversed(rgb)):
    num += n * (10 ** i)
if num % 4 == 0:
    print("YES")
else:
    print("NO")
