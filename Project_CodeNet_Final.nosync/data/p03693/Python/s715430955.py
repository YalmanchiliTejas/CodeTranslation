r = list(map(int, input().split()))

num = r[0]*100+r[1]*10+r[2]
if num%4==0:
    print("YES")
else:
    print("NO")