a,b,c = map(int, input().split())
check = a * 100 + b * 10 + c
if check % 4 == 0:
    print("YES")
else:
    print("NO")