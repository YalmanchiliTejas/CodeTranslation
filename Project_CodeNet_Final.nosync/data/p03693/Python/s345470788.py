l = raw_input().split(" ")
num=int(l[0])*100+int(l[1])*10+int(l[2])

if num%4==0:
    print("YES")
else:
    print("NO")
