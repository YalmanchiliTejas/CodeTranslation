h,w = (int(i) for i in input().split())
a = [input() for i in range(h)]
num = 0
for i in a: num+=i.count("#")
if num==h+w-1: print("Possible")
else: print("Impossible")