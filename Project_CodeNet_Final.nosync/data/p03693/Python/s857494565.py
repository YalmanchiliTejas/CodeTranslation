r,g,b = [int(x) for x in input().split()]
print("YES") if (r*100+g*10+b)%4==0 else print("NO")