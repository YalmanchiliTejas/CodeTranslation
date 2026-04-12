H,W = map(int,input().split())

A = []
for i in range(H):
    a = input()
    if "#" in a: A.append(a)
        
A = list(zip(*A))

B = []
for a in A:
    if "#" in a: B.append(a)
        
B = list(zip(*B))

for b in B:
    print("".join(b))