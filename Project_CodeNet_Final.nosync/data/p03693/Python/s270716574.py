N = input().split()
sum = int(N[0])*100 + int(N[1])*10 + int(N[2])

if sum%4 == 0:
    print("YES")
else:
    print("NO")
