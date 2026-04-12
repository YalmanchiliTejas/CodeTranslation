a, b, c = map(int, input().split())
if int("{}{}{}".format(a, b, c)) % 4 ==0: print("YES")
else: print("NO")