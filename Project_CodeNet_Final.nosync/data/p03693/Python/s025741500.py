data = list(map(str, input().split()))
s = "".join(data)
if int(s) % 4 == 0:
    print("YES")
else:
    print("NO")
