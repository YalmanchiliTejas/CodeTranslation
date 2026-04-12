line = input().split()
sum = line[0]+line[1]+line[2]
if int(sum)%4 == 0:
    print("YES")
else:
    print("NO")
