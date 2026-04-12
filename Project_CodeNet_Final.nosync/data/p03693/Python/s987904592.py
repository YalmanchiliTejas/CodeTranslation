r, g, b=map(str,input().split())
n = r+g+b
n = int(n)
if n % 4 ==0:
    print("YES")
else:
    print("NO")