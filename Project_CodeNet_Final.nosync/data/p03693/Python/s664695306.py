r,g,b = input().split()
se = r+g+b
se_num = int(se)
if se_num%4 == 0:
    print("YES")
else:
    print("NO")