R, G, B = list(map(int, input().split()))

RGB = 100*R + 10*G + B

if(RGB%4==0):
    print("YES")
else:
    print("NO")