x,y,z = map(int, input().split())
S = x * 100 + y * 10 + z
if S % 4 == 0:
    print("YES")
else:
    print("NO")