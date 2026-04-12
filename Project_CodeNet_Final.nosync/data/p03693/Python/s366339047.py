r, a, b = map(int, input().split())

if((r*100+a*10+b)%4==0):
    print("YES")
else:
    print("NO")