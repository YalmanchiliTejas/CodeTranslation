x=int(input())
age=[3,5,7]
if any(x==age[i] for i in range(3)):
    print("YES")
else:
    print("NO")