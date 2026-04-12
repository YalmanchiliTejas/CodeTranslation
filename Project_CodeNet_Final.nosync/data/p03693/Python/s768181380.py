x = list(map(int, input().split()))

if ((100*x[0]) + (10*x[1]) + (x[2])) %4 ==0:
    print("YES")
else:
    print("NO")
