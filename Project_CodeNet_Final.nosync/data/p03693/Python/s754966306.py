r , g , b= input().split()
res = r + g + b
if int(res) % 4 == 0:
    print("YES")
else:
    print("NO")