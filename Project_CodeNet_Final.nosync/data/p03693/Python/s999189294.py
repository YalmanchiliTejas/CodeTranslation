a, b, c = map(int, input().split())

suuji = a*100 + b*10 + c

if suuji%4 == 0:
    print("YES")

else:
    print("NO")