r, g, b = map(int, raw_input().split())
n = r * 100 + g * 10 + b
if n % 4 == 0 :
    print("YES")
else :
    print("NO")
