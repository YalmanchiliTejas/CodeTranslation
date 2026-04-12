a = [int(i) for i in input().split()]
a = a[0]*100 + a[1]*10 + a[2]
if a%4 == 0:
    print("YES")
else:
    print("NO")