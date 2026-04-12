in_list = input().split()

num = 100*int(in_list[0])+10*int(in_list[1])+int(in_list[2])

if num%4==0:
    print("YES")
else:
    print("NO")