N = int(input())
S = list(input())
K = int(input())
 
for i in S:
    if S[K-1] == i:
        print(i, end="")
    else:
        print("*", end="")
print()