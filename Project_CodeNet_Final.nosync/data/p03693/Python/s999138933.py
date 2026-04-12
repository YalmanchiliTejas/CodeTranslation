r, g, b = input().split()
ret = "NO"
n = int(r+g+b)
if n % 4 == 0:
    ret = "YES"
print(ret)