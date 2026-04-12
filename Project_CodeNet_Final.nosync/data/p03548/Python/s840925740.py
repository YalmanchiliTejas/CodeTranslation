#078b
X,Y,Z = map(int, input().split())

# X >= (Z+Y)*ans+Z
# (X-Z)/(Z+Y) >= ans
print((X-Z)//(Z+Y))