H,W=map(int,input().split())
A=[]
for _ in range(H):
    a=list(input())
    if sum(list(map(ord, a)))==ord(".")*W:
        continue
    A.append(a)

B=[]
for a in zip(*A):
    if sum(list(map(ord, a)))==ord(".")*len(a):
        continue
    B.append(a)

for b in zip(*B):
    print("".join(b))