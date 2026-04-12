buf=input()
rgb=int("".join(buf.split()))
if rgb%4==0:
    print("YES")
else:
    print("NO")