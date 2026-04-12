r,g,b=tuple(map(lambda x: int(x), raw_input().split()))
ans = "YES" if (100*r+10*g+b) % 4 == 0 else "NO"
print ans