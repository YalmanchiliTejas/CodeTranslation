r,g,b = input().split(" ")

if (int(r)*100+int(g)*10+int(b))%4==0 :
    print("YES")
else :
    print("NO")