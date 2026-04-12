r, g ,b = (i for i in input().split())
num = int(r+g+b)
print("YES" if num%4 == 0 else "NO")