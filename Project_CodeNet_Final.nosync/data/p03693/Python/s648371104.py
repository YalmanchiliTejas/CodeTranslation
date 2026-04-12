r, g, b = map(int, input().split())

num = (r * 100) + (g * 10) + b

num_mod = num % 4

if (num_mod == 0):
    print("YES")

else:
    print("NO")