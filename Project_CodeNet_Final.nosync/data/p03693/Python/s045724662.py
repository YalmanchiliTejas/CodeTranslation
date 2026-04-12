R,G,B=map(int,input().split())

if (R*100+G*10+B)%4==0:
    print("YES")
else:
    print("NO")