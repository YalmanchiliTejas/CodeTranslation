r,g,b = map(int,input().rstrip().split(" "))
print("YES" if (g * 10 + b) % 4 == 0 else "NO") 