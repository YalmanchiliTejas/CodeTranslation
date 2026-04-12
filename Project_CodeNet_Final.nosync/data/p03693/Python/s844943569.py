r, g, b= map(int, input().split())

ans = 10*g+b

if ans % 4==0:
    print("YES")
else:
    print("NO")