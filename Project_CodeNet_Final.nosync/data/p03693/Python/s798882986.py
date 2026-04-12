indata = [int(i) for i in input().split()]

a = indata[1]*10 + indata[2]*1
if a % 4 == 0:
    print("YES")
else:
    print("NO")
