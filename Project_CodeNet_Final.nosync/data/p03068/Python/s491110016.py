N = int(input())
S = input()
K = int(input())
x = S[K-1]
SS = []
for i in range(N):
    if not S[i] == x:
        SS.append("*")
    else:
        SS.append(x)
for c in SS:
    print(c,end = "")
print() 