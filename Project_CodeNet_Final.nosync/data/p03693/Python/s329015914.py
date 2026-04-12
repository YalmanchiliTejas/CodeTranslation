r, g, b = map(int, input().split())
print('YES' if int(str(r)+str(g)+str(b)) % 4 == 0 else 'NO')