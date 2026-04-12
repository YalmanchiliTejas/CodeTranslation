a = list(map(int,input().split(" ")))
s = a[0]*100 + a[1] *10 + a[2]
if s%4==0:
    print("YES")
else:
    print("NO")