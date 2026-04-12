s = input().split()

s = "".join(s)
s = int(s)
if s % 4 == 0:
    print("YES")
else:
    print("NO")