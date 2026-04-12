a,b,c = map(str,input().split())
n = int(a+b+c)
print("YES" if n % 4 == 0 else "NO")