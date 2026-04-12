H,W = map(int,input().split())
c = 0
for _ in range(H):
    c += input().count("#")

# #の数が最低限必要な数より多いとImpossibleとなる
print ("Impossible") if c > H+W-1 else print ("Possible")
