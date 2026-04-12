rgb = list(map(int,input().split()))
Num = rgb[0] * 100 + rgb[1] * 10 + rgb[2]

if Num % 4 == 0:
    print("YES")
else:
    print("NO")