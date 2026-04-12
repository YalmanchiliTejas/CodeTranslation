n = input()
tmp_n = n.split(" ")
num = int(tmp_n[0]+tmp_n[1]+tmp_n[2])

if num%4 == 0:
    print("YES")
else:
    print("NO")
