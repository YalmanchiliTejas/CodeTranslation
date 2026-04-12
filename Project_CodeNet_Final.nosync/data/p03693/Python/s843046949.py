int_r, int_g ,int_b = map(int, input().split())

if (int_r * 100 + int_g * 10 + int_b) % 4 == 0:
    print("YES")
else:
    print("NO")
