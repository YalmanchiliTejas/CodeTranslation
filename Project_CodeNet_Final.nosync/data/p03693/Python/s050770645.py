R,G,B = list(map(int,input().split()))
X = int(str(R)+str(G)+str(B))
if X%4==0:
    print("YES")
else:
    print("NO")