H,W=map(int, input().split())
A="".join(input() for _ in range(H))
print("Possible" if H+W-1==A.count("#") else "Impossible")