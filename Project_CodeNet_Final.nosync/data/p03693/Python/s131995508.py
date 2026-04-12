val = input().split()
num = val[0]+val[1]+val[2]
num = int(num)
print("YES" if num %4 == 0 else "NO")