n = [int(i) for i in input().split()]

if (n[0] * 100 + 10 * n[1] + n[2]) % 4 == 0:
    print("YES")
else:
    print("NO")