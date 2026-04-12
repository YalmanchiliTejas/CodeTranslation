a, b, c = map(int, input().split())
print("NO" if (b*10+c)%4 else "YES")