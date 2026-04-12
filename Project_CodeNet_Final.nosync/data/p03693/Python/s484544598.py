r,g,b = map(int,input().split())
a = r*100+g*10+b
msg = "YES" if a%4 == 0 else "NO"
print(msg)