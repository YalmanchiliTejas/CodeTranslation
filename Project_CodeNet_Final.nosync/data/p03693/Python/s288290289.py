line = list(map(str, input().split()))
target = int("".join(line))
if target % 4 == 0:
    print("YES")
else:
    print("NO")