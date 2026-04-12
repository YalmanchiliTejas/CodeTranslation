a,b,c = input().split()
s = int(a+b+c)
print(('NO','YES')[s%4==0])
