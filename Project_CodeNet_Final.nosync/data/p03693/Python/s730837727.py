a, b, c = map(int, input().replace(" ", ""))
N = int(100*a+10*b+c)
print("YES" if N%4==0 else "NO")