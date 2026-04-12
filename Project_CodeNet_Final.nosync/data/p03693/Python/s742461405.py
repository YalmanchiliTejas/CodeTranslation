temp = input().rstrip().split(" ")
r = temp[0]
g = temp[1]
b = temp[2]
ans = int(r+g+b)
if ans % 4 == 0 :
    print("YES")
else:
    print("NO")