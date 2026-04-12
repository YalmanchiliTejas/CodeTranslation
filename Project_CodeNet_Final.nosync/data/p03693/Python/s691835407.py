a = input()

b,c,d = map(int, a.split())

if (b*100 + c*10 + d) % 4 == 0:
    print("YES")
else:
    print("NO")
