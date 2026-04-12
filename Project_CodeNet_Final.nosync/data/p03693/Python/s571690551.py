l = list(map(int, input().split()))
m = 100 * l[0] + 10 * l[1] + l[2]
if m % 4 == 0:
    print("YES")
else:
    print("NO")