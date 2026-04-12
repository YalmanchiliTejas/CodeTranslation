def read(): return list(map(int, input().split()))

c = read()
print("YES" if (100*c[0] + 10*c[1] + c[2]) % 4 == 0 else "NO")